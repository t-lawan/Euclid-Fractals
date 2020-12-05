//
//  Cell.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 21/11/2020.
//

#include "Cell.h"

Cell::Cell(int _x,  int _y, int _width, int _height){
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    numOfPlants = 0;
    if(ofRandom(1) >= 0.5) {
        hasFungus = false;
    } else {
        hasFungus = true;
    }
    
    // Set Rainfall between 0 and 255
    rainfall = ofRandom(0, 50);
    capital = ofRandom(MIN_CAPITAL, MAX_CAPITAL);
}

bool Cell::isWithinBounds(ofVec2f position) {
    if(position.x > x &&
       position.x < x + width &&
       position.y > y &&
       position.y < y + height){
        
        return true;
    }
    return false;
}

void Cell::checkIfPlantsAreInCurrent(
                            vector<Sugarcane> _sugarcanes,
                            vector<Soybean> _soybeans) {
    numOfPlants = 0;
    // Check if sugarcane is on cell
    for (auto sugarcane : _sugarcanes)
    {
        if(isWithinBounds(sugarcane.position)){
                numOfPlants++;
        }
    };
    
    for (auto soybean : _soybeans)
    {
        if(isWithinBounds(soybean.position)){
                numOfPlants++;
        }
    };
}

void Cell::updateJammerProuctionRate(){
    float currentNumber = jammerProductionRate;
    jammerProductionRate = jammerProductionRate + previousJammerProductionRate;
    previousJammerProductionRate = currentNumber;
}
