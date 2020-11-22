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
        AbstractMovingAgent(ofVec2f _position, DNA _dna) : AbstractAgent(_position, _dna) {};
        virtual ~AbstractMovingAgent(){};
//        virtual AbstractMovingAgent reproduce() = 0;
    
};
#endif /* AbstractMovingAgent_h */
