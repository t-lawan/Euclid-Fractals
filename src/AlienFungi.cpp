//
//  AlienFungi.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 30/11/2020.
//

#include "AlienFungi.h"

AlienFungi::AlienFungi(){
    maxNumberOfPlantsOnCell = 0;
    threshold = 5;
    img.load("fungi.png");
//    img.resize(10, 10);
}

void AlienFungi::update(vector<Cell> cells, vector<Sugarcane> _sugarcanes, vector<Soybean> _soybeans, vector<Pollinator> _pollinators) {
    // Get cells that have fungus
    //Set cells to manipulate
    // Is being manipulated
    setMaxNumberOfPlants(cells);
    setCellsToManipulate(cells);
    manipulateAgentsOnCells(_sugarcanes, _soybeans, _pollinators);
}

void AlienFungi::setMaxNumberOfPlants(vector<Cell> cells){
    maxNumberOfPlantsOnCell = 0;
    for (auto cell : cells)
    {
        if(cell.numOfPlants >= maxNumberOfPlantsOnCell){
            maxNumberOfPlantsOnCell = cell.numOfPlants;
        }
    };
}

void AlienFungi::setCellsToManipulate(vector<Cell> cells){
    cellsToManipulate.clear();
    for (auto cell : cells)
    {
        if((maxNumberOfPlantsOnCell > 0) && (cell.numOfPlants >= (accelerationLimit * maxNumberOfPlantsOnCell)))
        {
            cellsToManipulate.push_back(cell);
        }
    };
    
}

bool AlienFungi::isManipulating(Cell cell){
    if((maxNumberOfPlantsOnCell > threshold) && (cell.numOfPlants >= (accelerationLimit * maxNumberOfPlantsOnCell))){
        return true;
    }
    
    return false;
}

void AlienFungi::manipulateAgentsOnCells(vector<Sugarcane> _sugarcanes, vector<Soybean> _soybeans, vector<Pollinator> _pollinators){
    if(maxNumberOfPlantsOnCell > threshold){
        for(auto cell : cellsToManipulate) {
            for (auto sugarcane : _sugarcanes)
            {
                if(cell.isWithinBounds(sugarcane.position)){
                    sugarcane.decelerate();
                }
            };
            
            for (auto soybean : _soybeans)
            {
                if(cell.isWithinBounds(soybean.position)){
                        soybean.decelerate();
                }
            };
            
            for (auto pollinator : _pollinators)
            {
                if(cell.isWithinBounds(pollinator.position)){
                        pollinator.decelerate();
                }
            };
        }
    }
}

