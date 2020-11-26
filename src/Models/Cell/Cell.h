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
    
        int numOfPlants;

        bool hasFungus;
        float capital;
        float rainfall;
        Cell(int _x = 0,  int _y = 0);
        bool isWithinBounds(ofVec2f position, int width, int height);
    
    protected:
        int MIN_CAPITAL = 0;
        int MAX_CAPITAL = 100;
};
#endif /* Cell_h */
