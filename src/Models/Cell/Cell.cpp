//
//  Cell.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 21/11/2020.
//

#include "Cell.h"

Cell::Cell(int _x,  int _y){
    x = _x;
    y = _y;
    // Set Rainfall between 0 and 255
    rainfall = ofRandom(0, 50);
    capital = ofRandom(MIN_CAPITAL, MAX_CAPITAL);
}

bool Cell::isWithinBounds(ofVec2f position, int width, int height) {
    if(position.x > x &&
       position.x < x + width &&
       position.y > y &&
       position.y < y + height){
        
        return true;
    }
    return false;
}
