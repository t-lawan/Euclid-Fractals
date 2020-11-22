//
//  AbstractAgent.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 22/11/2020.
//

#ifndef AbstractAgent_h
#define AbstractAgent_h

#include "ofMain.h"
#include <stdio.h>
#include "DNA.h"

class AbstractAgent {
    public:
        float health;
        float reproduction_rate;
        ofVec2f position;
        DNA dna;
    
        AbstractAgent(ofVec2f _position, DNA _dna);
        virtual ~AbstractAgent(){};
        virtual bool shouldReproduce() = 0;
//        virtual AbstractAgent reproduce() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual bool dead() = 0;
    
};

#endif /* AbstractAgent_h */
