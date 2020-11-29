//
//  Grid.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#include "Grid.h"

Grid::Grid(int _numX, int _numY){
    cout << "GRID BUILT" << endl;
    numX = _numX;
    numY = _numY;
    stepX = ofGetWidth()/numX;
    stepY = ofGetHeight()/numY;
    setupCells();
}

void Grid::setupCells(){
    for(int gridY = 0; gridY < ofGetHeight(); gridY = gridY + stepY) {
        for(int gridX = 0; gridX < ofGetWidth(); gridX = gridX + stepX) {
            Vec2Key coordinates = Vec2Key(gridX, gridY);
            Cell cell(gridX, gridY);

            if(cells.count(coordinates) < 1){
                cells.insert(make_pair(coordinates,cell));
            }
        }
    }
}

Cell Grid::getCell(int x, int y){
    int cellX = floor(x/ stepX) * stepX;
    int cellY = floor(y/stepY) * stepY;
    Vec2Key key = Vec2Key(cellX, cellY);
    return cells[key];
}

void Grid::updateCell(int x, int y, Cell newCell) {
    Vec2Key key(x, y);
    cells[key] = newCell;
}

void Grid::update(vector<Sugarcane> _sugarcanes,  vector<Soybean> _soybeans) {
    for(int gridY = 0; gridY < ofGetHeight(); gridY = gridY + stepY) {
        for(int gridX = 0; gridX < ofGetWidth(); gridX = gridX + stepX) {
            Cell cell = getCell(gridX, gridY);
            cell = checkIfPlantsAreOnCell(cell, _sugarcanes, _soybeans);
            updateCell(gridX, gridY, cell);
        }
    }
    
    setMaxNumberOfPlants();
    vector<Cell> cellsWithHighNumberOfPlants = findCellsWithHighNumberOfPlants();
    acceleratePlantsOnCells(cellsWithHighNumberOfPlants, _sugarcanes, _soybeans);
    
};

vector<Cell> Grid::findCellsWithHighNumberOfPlants(){
    vector<Cell> cellsWithHighNumberOfPlants;
    for (auto const& cell : cells)
    {
        if((maxNumberOfPlantsOnCell > 0) && (cell.second.numOfPlants >= (0.7 * maxNumberOfPlantsOnCell)))
        {
            cellsWithHighNumberOfPlants.push_back(cell.second);
        }
    };
    
    return cellsWithHighNumberOfPlants;
}

void Grid::acceleratePlantsOnCells(
                                   vector<Cell> cellsWithHighNumberOfPlants,
                                   vector<Sugarcane> _sugarcanes,
                                   vector<Soybean> _soybeans){
    if(maxNumberOfPlantsOnCell > plantThreshold) {
        for (auto cell : cellsWithHighNumberOfPlants)
        {
            for (auto sugarcane : _sugarcanes)
            {
                if(cell.isWithinBounds(sugarcane.position, stepX, stepY)){
                        sugarcane.accelerate();
                    }
            };
            
            for (auto soybean : _soybeans)
            {
                if(cell.isWithinBounds(soybean.position, stepX, stepY)){
                        soybean.accelerate();
                    }
            };
        };
    }
}

Cell Grid::checkIfPlantsAreOnCell(Cell cell,
                                  vector<Sugarcane> _sugarcanes,
                                  vector<Soybean> _soybeans){
    cell.numOfPlants = 0;
    
    // Check if sugarcane is on cell
    for (auto const& sugarcane : _sugarcanes)
    {
        if(cell.isWithinBounds(sugarcane.position, stepX, stepY)){
                cell.numOfPlants++;
            }
    };
    
    // Check if soybean is on cell
    for (auto const& soybean : _soybeans)
    {
        if(cell.isWithinBounds(soybean.position, stepX, stepY)){
                cell.numOfPlants++;
            }
    };
    
    return cell;
}


void Grid::setMaxNumberOfPlants() {
    int maxNumOfPlants = 0;
    for (auto const& cel : cells)
    {
        if(cel.second.numOfPlants >= maxNumOfPlants){
            maxNumOfPlants = cel.second.numOfPlants;
        }
    };
    
    maxNumberOfPlantsOnCell = maxNumOfPlants;
}



void Grid::draw(){

    ofSetRectMode(OF_RECTMODE_CORNER);
    for(int gridY = 0; gridY < ofGetHeight(); gridY = gridY + stepY) {
        for(int gridX = 0; gridX < ofGetWidth(); gridX = gridX + stepX) {
            ofPushMatrix();
            // Draw Grid Outlines
            ofNoFill();
            ofTranslate(gridX, gridY);
            ofSetColor(0, 5);
            ofDrawRectangle(0, 0, stepX, stepY);
            
            // Draw Blue Box To Show Capital amount
            ofFill();
            Cell cell = getCell(gridX, gridY);
            ofSetColor(0, 255, 0, cell.capital);
            ofDrawRectangle(0, 0, stepX, stepY);
       
            
            // Draw Number Of Plants Value
            ofSetColor(0);
            ofDrawBitmapString("Plant Number: " + to_string(cell.numOfPlants), stepX * 0.1, stepY * 0.9);
            ofPopMatrix();
        }
    }
}

