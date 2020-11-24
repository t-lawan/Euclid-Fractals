//
//  AbstractParasiticAgent.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 24/11/2020.
//

#ifndef AbstractParasiticAgent_h
#define AbstractParasiticAgent_h

#include <stdio.h>

#include "AbstractAgent.h"
#include "Food.h"
#include "DNA.h"

class AbstractParasiticAgent : public AbstractAgent {
    public:
        int north, northEast, east, southEast, south, southWest, west, northWest;
        int direction;
    
        virtual void eat(Food f) = 0;
        virtual int isOnFood(Food f) = 0;
        virtual void checkBorders() = 0;
        AbstractParasiticAgent(ofVec2f _position, DNA _dna) : AbstractAgent(_position, _dna) {
            vitality = ofRandom(MIN_HEALTH, MAX_HEALTH);
            
            // Gene 0 determines maxspeed and r
             // The bigger the bloop, the slower it is
            r = ofMap(dna.genes[0], 0, 1, MIN_SIZE, MAX_SIZE);
            reproduction_rate = ofMap(dna.genes[0], 0, 1, MAX_REPRODUCTION_RATE, MIN_REPRODUCTION_RATE);
            mutation_rate = ofMap(dna.genes[0], 0, 1, MAX_MUTATION_RATE, MIN_MUTATION_RATE);
            
            north = 0;
            northEast = 1;
            east = 2;
            southEast = 3;
            south = 4;
            southWest = 5;
            west = 6;
            northWest = 7;
        };
        virtual ~AbstractParasiticAgent(){};
//        virtual AbstractMovingAgent reproduce() = 0;
    
};

#endif /* AbstractParasiticAgent_h */
