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

class AbstractParasiticAgent {
    public:
    
        virtual void eat(Food f) = 0;
        virtual int isOnFood(Food f) = 0;
        virtual void checkBorders() = 0;
        AbstractParasiticAgent(ofVec2f _position, DNA _dna) {

        };
        virtual ~AbstractParasiticAgent(){};
//        virtual AbstractMovingAgent reproduce() = 0;
    
};

#endif /* AbstractParasiticAgent_h */
