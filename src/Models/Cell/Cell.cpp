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
    // Set Rainfall between 0 and 50
    rainfall = ofRandom(0, 50);
}
