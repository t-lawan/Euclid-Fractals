//
//  Capital.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 29/11/2020.
//

#ifndef Capital_h
#define Capital_h

#include <stdio.h>
#include "ofMain.h"
#include "Soybean.h"
#include "Sugarcane.h"
#include "Cell.h"
class Capital {
    public:
        ofImage img;
        int maxNumberOfPlantsOnCell;
        int threshold;
        float accelerationLimit = 0.7;
        vector<Cell> cellsToManipulate;
        Capital();
        void update(vector<Cell> cells, vector<Sugarcane> _sugarcanes, vector<Soybean> _soybeans);
        void setMaxNumberOfPlants(vector<Cell> cells);
        void setCellsToManipulate(vector<Cell> cells);
        void manipulatePlantsOnCells(vector<Sugarcane> _sugarcanes, vector<Soybean> _soybeans);
        bool isManipulating(Cell cell);
};

#endif /* Capital_h */
