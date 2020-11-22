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
#include "AbstractMovingAgent.h"

class Agent : public AbstractMovingAgent {
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
    
    Agent(ofVec2f _position, DNA _dna) : AbstractMovingAgent(_position, _dna){
        health = ofRandom(100, 200);
        xoff = ofRandom(0, 1000);
        yoff = ofRandom(0, 1000);
        
        // Gene 0 determines maxspeed and r
         // The bigger the bloop, the slower it is
        maxspeed = ofMap(dna.genes[0], 0, 1, 15, 0);
        r = ofMap(dna.genes[0], 0, 1, 5, 20);
        reproduction_rate = ofMap(dna.genes[0], 0, 1, 0.003, 0.001);
    };
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
