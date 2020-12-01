//
//  AlienFungi.hpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 30/11/2020.
//

#ifndef AlienFungi_h
#define AlienFungi_h

#include <stdio.h>
#include "ofMain.h"
#include "Soybean.h"
#include "Sugarcane.h"
#include "Cell.h"
#include "Pollinator.h"

class AlienFungi {
    public:
        int maxNumberOfPlantsOnCell;
        int threshold;
        float accelerationLimit = 0.5;
        vector<Cell> cellsToManipulate;
        AlienFungi();
        void update(vector<Cell> cells, vector<Sugarcane> _sugarcanes, vector<Soybean> _soybeans, vector<Pollinator> _pollinators);
        void setMaxNumberOfPlants(vector<Cell> cells);
        void setCellsToManipulate(vector<Cell> cells);
        void manipulateAgentsOnCells(vector<Sugarcane> _sugarcanes, vector<Soybean> _soybeans, vector<Pollinator> _pollinators);
        bool isManipulating(Cell cell);
};
#endif /* AlienFungi_hpp */
