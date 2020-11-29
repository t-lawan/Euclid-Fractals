//
//  Grid.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#include "Grid.h"

Grid::Grid(int _numX, int _numY){
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
            Cell cell(gridX, gridY, stepX, stepY);

            if(cells.count(coordinates) < 1){
                cells.insert(make_pair(coordinates,cell));
            }
        }
    }
}

void Grid::update(vector<Sugarcane> _sugarcanes,  vector<Soybean> _soybeans) {
    // Update Max Number Of Plants variable in Cell
    for(int gridY = 0; gridY < ofGetHeight(); gridY = gridY + stepY) {
        for(int gridX = 0; gridX < ofGetWidth(); gridX = gridX + stepX) {
            Cell cell = getCell(gridX, gridY);
            cell.checkIfPlantsAreInCurrent(_sugarcanes, _soybeans);
            updateCell(gridX, gridY, cell);
        }
    }
    
    vector<Cell> cellVector = convertCellsMapToVector();
    capital.update(cellVector, _sugarcanes, _soybeans);
};


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


vector<Cell> Grid::convertCellsMapToVector(){
    vector<Cell> cellVector;
    for (auto cell : cells)
    {
        cellVector.push_back(cell.second);
    };
    
    return cellVector;
}

