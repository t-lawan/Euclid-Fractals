//
//  Plant.hpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 20/11/2020.
//

#ifndef Plant_h
#define Plant_h

#include <stdio.h>
#include "ofMain.h"
#include "DNA.h"
#include "Food.h"
#include "SimulationObject.h"

class Plant : public SimulationObject {
    public:
    
    float plantHealth;   // Life timer
    //float xoff;     // For perlin noise
    //float yoff;
    // DNA will determine size
    float r;
    ofVec2f position;
    DNA dna;
    
    Plant(ofVec2f _position, DNA _dna);
    void plantEat(Food f);
    int plantIsOnFood(Food f);
    Plant plantReproduce();
    bool plantShouldReproduce();
    void update();
    void plantCheckBorders();
    void draw();
    bool dead();
    
    int north, northEast, east, southEast, south, southWest, west, northWest;
    int direction;
};
#endif /* Plant_h*/
