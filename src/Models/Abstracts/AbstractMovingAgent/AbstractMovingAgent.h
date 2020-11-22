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
        float maxspeed;
    
        virtual void eat(Food f) = 0;
        virtual int isOnFood(Food f) = 0;
        virtual void checkBorders() = 0;
        AbstractMovingAgent(ofVec2f _position, DNA _dna) : AbstractAgent(_position, _dna) {
            health = ofRandom(100, 200);
            xoff = ofRandom(0, 1000);
            yoff = ofRandom(0, 1000);
            
            // Gene 0 determines maxspeed and r
             // The bigger the bloop, the slower it is
            maxspeed = ofMap(dna.genes[0], 0, 1, 15, 0);
            r = ofMap(dna.genes[0], 0, 1, 5, 20);
            reproduction_rate = ofMap(dna.genes[0], 0, 1, 0.003, 0.001);
            mutation_rate = ofMap(dna.genes[0], 0, 1, 0.4, 0.1);
        };
        virtual ~AbstractMovingAgent(){};
//        virtual AbstractMovingAgent reproduce() = 0;
    
};
#endif /* AbstractMovingAgent_h */
