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
            Cell cell = Cell(gridX, gridY);
            cells.insert(make_pair(coordinates,cell));
        }
    }
}

Cell Grid::getCell(float x, float y){
    int cellX = floor(x/ stepX);
    int cellY = floor(y/stepY);
    Vec2Key key = Vec2Key(cellX, cellY);
    return cells.find(key)->second;
}

void Grid::draw(){
    ofSetColor(0, 5);
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    int stepY = ofGetHeight()/numY;
    int stepX = ofGetWidth()/numX;
    for(int gridY = 0; gridY < ofGetHeight(); gridY = gridY + stepY) {
        for(int gridX = 0; gridX < ofGetWidth(); gridX = gridX + stepX) {
            ofPushMatrix();
            ofNoFill();
            ofTranslate(gridX, gridY);
            ofDrawRectangle(0, 0, stepX, stepY);
            ofFill();
            ofPopMatrix();
        }
    }
}

