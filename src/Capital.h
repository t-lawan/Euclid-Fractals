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
        int maxNumberOfPlantsOnCell;
        int threshold;
        vector<Cell> cellsToManipulate;
        Capital();
        void setMaxNumberOfPlants(vector<Cell> cells);
        void setCellsToManipulate(vector<Cell> cells);
        void acceleratePlantsOnCells(vector<Sugarcane> _sugarcanes, vector<Soybean> _soybeans);
        void setMaxNumberOfPlants();
};

#endif /* Capital_h */
