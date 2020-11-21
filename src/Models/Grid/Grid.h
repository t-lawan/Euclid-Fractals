//
//  Grid.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#ifndef Grid_h
#define Grid_h

#include <stdio.h>
#include "ofMain.h"
#include "Cell.h"
#include "Vec2Key.h"

class Grid {
    public:
        int numX = 50;
        int numY = 50;
        int stepX;
        int stepY;
        Grid(int _numX, int _numY);
        void draw();
        void setupCells();
        Cell getCell(float x, float y);
        map<Vec2Key, Cell> cells;
};
#endif /* Grid_h */
