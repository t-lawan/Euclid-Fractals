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
#include "Sugarcane.h"
#include "Soybean.h"

class Cell {
    public:
        int x;
        int y;
    
        int width;
        int height;
        int numOfPlants;

        bool hasFungus;
        float capital;
        float rainfall;
    
        float previousJammerProductionRate = 0.0;
        float jammerProductionRate = 0.01;
        Cell(int _x = 0,  int _y = 0, int _width = 0, int _height = 0);
        bool isWithinBounds(ofVec2f position);
        void checkIfPlantsAreInCurrent(
                          vector<Sugarcane> _sugarcanes,
                          vector<Soybean> _soybeans);
        void updateJammerProuctionRate();
    protected:
        int MIN_CAPITAL = 0;
        int MAX_CAPITAL = 100;
};
#endif /* Cell_h */
