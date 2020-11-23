//
//  AbstractMovingAgent.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 22/11/2020.
//

#ifndef AbstractMovingAgent_h
#define AbstractMovingAgent_h

#include <stdio.h>
#include "AbstractAgent.h"
#include "Food.h"
#include "DNA.h"

class AbstractMovingAgent : public AbstractAgent {
    public:
        float xoff;       // For perlin noise
        float yoff;
        float r;
        float MIN_SIZE = 5;
        float MAX_SIZE = 20;
    
        float maxspeed;
        float MIN_SPEED = 0.5;
        float MAX_SPEED = 15;
    
        float minMutationRate;
        float maxMutationRate;
        virtual void eat(Food f) = 0;
        virtual int isOnFood(Food f) = 0;
        virtual void checkBorders() = 0;
        AbstractMovingAgent(ofVec2f _position, DNA _dna) : AbstractAgent(_position, _dna) {
            health = ofRandom(MIN_HEALTH, MAX_HEALTH);
            xoff = ofRandom(0, 1000);
            yoff = ofRandom(0, 1000);
            
            // Gene 0 determines maxspeed and r
             // The bigger the bloop, the slower it is
            maxspeed = ofMap(dna.genes[0], 0, 1, MAX_SPEED, MIN_SPEED);
            r = ofMap(dna.genes[0], 0, 1, MIN_SIZE, MAX_SIZE);
            reproduction_rate = ofMap(dna.genes[0], 0, 1, MAX_REPRODUCTION_RATE, MIN_REPRODUCTION_RATE);
            mutation_rate = ofMap(dna.genes[0], 0, 1, MAX_MUTATION_RATE, MIN_MUTATION_RATE);
        };
        virtual ~AbstractMovingAgent(){};
//        virtual AbstractMovingAgent reproduce() = 0;
    
};
#endif /* AbstractMovingAgent_h */
