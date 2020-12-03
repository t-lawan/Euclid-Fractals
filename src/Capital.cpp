//
//  Capital.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 29/11/2020.
//

#include "Capital.h"


Capital::Capital(){
    maxNumberOfPlantsOnCell = 0;
    threshold = 10;
    img.load("fungi.png");
    img.resize(10, 10);
}

void Capital::update(vector<Cell> cells, vector<Sugarcane> _sugarcanes, vector<Soybean> _soybeans) {
    setMaxNumberOfPlants(cells);
    setCellsToManipulate(cells);
    manipulatePlantsOnCells(_sugarcanes, _soybeans);
}

void Capital::setMaxNumberOfPlants(vector<Cell> cells){
    maxNumberOfPlantsOnCell = 0;
    for (auto cell : cells)
    {
        if(cell.numOfPlants >= maxNumberOfPlantsOnCell){
            maxNumberOfPlantsOnCell = cell.numOfPlants;
        }
    };
}

void Capital::setCellsToManipulate(vector<Cell> cells){
    cellsToManipulate.clear();
    for (auto cell : cells)
    {
        if((maxNumberOfPlantsOnCell > 0) && (cell.numOfPlants >= (accelerationLimit * maxNumberOfPlantsOnCell)))
        {
            cellsToManipulate.push_back(cell);
        }
    };
    
}

bool Capital::isManipulating(Cell cell){
    if((maxNumberOfPlantsOnCell > threshold) && (cell.numOfPlants >= (accelerationLimit * maxNumberOfPlantsOnCell))){
        return true;
    }
    
    return false;
}

void Capital::manipulatePlantsOnCells(vector<Sugarcane> _sugarcanes, vector<Soybean> _soybeans){
    if(maxNumberOfPlantsOnCell > threshold){
        for(auto cell : cellsToManipulate) {
            for (auto sugarcane : _sugarcanes)
            {
                if(cell.isWithinBounds(sugarcane.position)){
                    sugarcane.accelerate();
                }
            };
            
            for (auto soybean : _soybeans)
            {
                if(cell.isWithinBounds(soybean.position)){
                        soybean.accelerate();
                }
            };
        }
    }
}


