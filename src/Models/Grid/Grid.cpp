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
//                cells[coordinates] = cell;
                cells.insert(make_pair(coordinates,cell));
            }
        }
    }
}

void Grid::updatePopulation(int _population, int _numOfDead){
    population = _population;
    numOfDead = _numOfDead;
}

void Grid::update(
                  vector<Sugarcane> _sugarcanes,
                  vector<Soybean> _soybeans,
                  vector<Pollinator> _pollinators,
                  vector<PlantDestroyer> _plantDestroyers)
{
    updateCells(_sugarcanes, _soybeans);
    vector<Cell> cellVector = convertCellsMapToVector();
    capital.update(cellVector, _sugarcanes, _soybeans);
    alienFungi.update(cellVector, _sugarcanes, _soybeans, _pollinators, _plantDestroyers);
};


void Grid::draw(){

    ofSetRectMode(OF_RECTMODE_CORNER);
    for(int gridY = 0; gridY < ofGetHeight(); gridY = gridY + stepY) {
        for(int gridX = 0; gridX < ofGetWidth(); gridX = gridX + stepX) {
            ofPushMatrix();
            // Draw Grid Outlines
            ofNoFill();
            ofTranslate(gridX, gridY);
//            ofSetColor(0, 5);
//            ofDrawRectangle(0, 0, stepX, stepY);
            
            // Draw Boxes if capital is acting on cell
            ofFill();
            Cell cell = getCell(gridX, gridY);
            
            if(capital.isManipulating(cell)){
                // Draw Grid if Capital Exists
                ofSetColor(255, 150);
                for(int rectY = 0; rectY < stepY; rectY += (stepY/8)){
                    for(int rectX = 0; rectX < stepX; rectX += (stepX/8)){
                        if((rectY %2 == 0 && rectX %2 == 0) || (rectY%2 == 1 && rectX%2 == 1) ){
                            ofPushMatrix();
                             ofTranslate(rectX, rectY);
                             capital.img.draw(0, 0, stepX/8, stepY/8);
                             ofPopMatrix();
                        }
                    }
                }
            }
            //Draw boxes if fungi is acting on cell
            if(alienFungi.isManipulating(cell)) {
                //                c.setHsb(85, 100, 168);
                ofSetColor(255, 100);
                for(int rectY = 0; rectY < stepY; rectY += (stepY/8)){
                    for(int rectX = 0; rectX < stepX; rectX += (stepX/8)){
                        if((rectY %2 == 0 && rectX %2 == 1) || (rectY%2 == 1 && rectX%2 == 0) ){
                            ofPushMatrix();
                             ofTranslate(rectX, rectY);
                            alienFungi.img.draw(0, 0, stepX/8, stepY/8);
                             ofPopMatrix();
                        }
                    }
                }
            }
       
            
            // Draw Number Of Plants Value
            ofSetColor(0);
//            ofDrawBitmapString("Plant Pop: " + to_string(cell.numOfPlants), stepX * 0.1, stepY * 0.9);
            ofPopMatrix();
        }
    }
}

Cell Grid::getCell(int x, int y){
    int cellX = floor(x/ stepX) * stepX;
    int cellY = floor(y/stepY) * stepY;
    Vec2Key key = Vec2Key(cellX, cellY);
    Cell cell = cells[key];
    return cell;
}

void Grid::updateCells(vector<Sugarcane> _sugarcanes,  vector<Soybean> _soybeans){
    // Update Max Number Of Plants variable in Cell
    for(int gridY = 0; gridY < ofGetHeight(); gridY = gridY + stepY) {
        for(int gridX = 0; gridX < ofGetWidth(); gridX = gridX + stepX) {
            Cell cell = getCell(gridX, gridY);
            cell.checkIfPlantsAreInCurrent(_sugarcanes, _soybeans);
            updateCell(gridX, gridY, cell);
        }
    }
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

