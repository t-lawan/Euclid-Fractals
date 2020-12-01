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
#include "AbstractMovingAgent.h"

class Agent : public AbstractMovingAgent {
    public:
        Agent(ofVec2f _position, DNA _dna) : AbstractMovingAgent(_position, _dna){
            colour = ofColor::blue;
            MIN_SIZE = 10;
            MAX_SIZE = 20;
            r = MAX_SIZE;
            MIN_REPRODUCTION_RATE = 0.000075;
            MAX_REPRODUCTION_RATE = 0.00015;
            MIN_MUTATION_RATE = 0.1;
            MAX_MUTATION_RATE = 0.2;
            DETERIORATION_RATE = 0.2;
            IMG_NAME = "fairy.png";
        };
        void eat(Food f);
        int isOnFood(Food f);
        Agent reproduce();
        void setup();
        bool shouldReproduce();
        void update();
        void checkBorders();
        void draw();
        bool dead();

        void accelerate();
        void decelerate();
};
#endif /* Agent_hpp */
