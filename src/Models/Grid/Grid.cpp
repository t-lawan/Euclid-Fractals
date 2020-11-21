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
