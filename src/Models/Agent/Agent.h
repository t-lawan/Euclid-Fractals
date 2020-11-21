//
//  Agent.hpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#ifndef Agent_h
#define Agent_h

#include <stdio.h>
#include "ofMain.h"
#include "DNA.h"
#include "Food.h"
#include "SimulationObject.h"

class Agent : public SimulationObject {
    public:
        
        float health;     // Life timer
        float xoff;       // For perlin noise
        float yoff;
        // DNA will determine reproductivity_rate, size and maxspeed
        float reproduction_rate;
        float r;
        float maxspeed;
        ofVec2f position;
        DNA dna;
    
        Agent(ofVec2f _position, DNA _dna);
        void eat(Food f);
        int isOnFood(Food f);
        Agent reproduce();
        bool shouldReproduce();   
        void update();
        void checkBorders();
        void draw();
        bool dead();
};
#endif /* Agent_hpp */
