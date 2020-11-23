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
                // DNA will determine reproductivity_rate, size and maxspeed
        float vitality;
        float MIN_HEALTH = 100;
        float MAX_HEALTH = 200;
        float DETERIORATION_RATE = 0.2;

        float mutation_rate;
        float MIN_MUTATION_RATE = 0.1;
        float MAX_MUTATION_RATE = 0.4;
    
        float reproduction_rate;
        float MIN_REPRODUCTION_RATE = 0.001;
        float MAX_REPRODUCTION_RATE = 0.003;
    
        float r;
        float MIN_SIZE = 5;
        float MAX_SIZE = 20;
    
        ofVec2f position;
        DNA dna;
        ofColor colour = ofColor::orange;
    
        AbstractAgent(ofVec2f _position, DNA _dna);
        virtual ~AbstractAgent(){};
        virtual bool shouldReproduce() = 0;
//        virtual AbstractAgent reproduce() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual bool dead() = 0;
    
};

#endif /* AbstractAgent_h */
