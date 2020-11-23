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
