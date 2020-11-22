//
//  AbstractStaticAgent.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 22/11/2020.
//

#ifndef AbstractStaticAgent_h
#define AbstractStaticAgent_h

#include <stdio.h>

#include "AbstractAgent.h"
#include "Food.h"
#include "DNA.h"

class AbstractStaticAgent : public AbstractAgent {
    public:
        float r;
        int north, northEast, east, southEast, south, southWest, west, northWest;
        int direction;
    
        virtual void eat(Food f) = 0;
        virtual int isOnFood(Food f) = 0;
        virtual void checkBorders() = 0;
        AbstractStaticAgent(ofVec2f _position, DNA _dna) : AbstractAgent(_position, _dna) {
            health = ofRandom(100, 200);
            
            // Gene 0 determines maxspeed and r
             // The bigger the bloop, the slower it is
            r = ofMap(dna.genes[0], 0, 1, 5, 20);
            reproduction_rate = ofMap(dna.genes[0], 0, 1, 0.003, 0.001);
            mutation_rate = ofMap(dna.genes[0], 0, 1, 0.4, 0.1);
        };
        virtual ~AbstractStaticAgent(){};
//        virtual AbstractMovingAgent reproduce() = 0;
    
};
#endif /* AbstractStaticAgent_h*/
