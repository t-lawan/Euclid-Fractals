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

class Grid {
    public:
        Grid(int _numX, int _numY);
        void draw();
        int numX = 50;
        int numY = 50;
};
#endif /* Grid_h */
