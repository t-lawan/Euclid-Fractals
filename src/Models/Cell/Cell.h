//
//  Cell.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 21/11/2020.
//

#ifndef Cell_h
#define Cell_h

#include <stdio.h>
#include "ofMain.h"

class Cell {
    public:
        int x;
        int y;
        bool hasFungus;
        float rainfall;
        Cell(int _x,  int _y);
};
#endif /* Cell_h */
