//
//  Jammer.h
//  Euclid Fractals
//
//  Created by Michael Kuhn on 12/1/20.
//

#ifndef Jammer_h
#define Jammer_h

#include <stdio.h>
#include "ofMain.h"
#include "DNA.h"
#include "Food.h"
#include "AbstractMovingAgent.h"
#include "Soybean.h"
#include "Sugarcane.h"
class Jammer : public AbstractMovingAgent {
    public:
        Jammer(ofVec2f _position, DNA _dna) : AbstractMovingAgent(_position, _dna){
            colour = ofColor::purple;
            MIN_REPRODUCTION_RATE = 0.0001;
            MAX_REPRODUCTION_RATE = 0.001;
            MIN_MUTATION_RATE = 0.1;
            MAX_MUTATION_RATE = 0.2;
            MIN_SIZE = 10;
            MAX_SIZE = 20;
            MIN_SPEED = 0.5;
            MAX_SPEED = 15;
            DETERIORATION_RATE = 0.5;
            IMG_NAME = "virus.png";
            setup();
        };
        void eat(Food f);
        int isOnFood(Food f);
        int isOnSugarCanes(vector<Sugarcane> sugarcanes);
        int isOnSoybeans(vector<Soybean> soybeans);
        Jammer reproduce();
        bool shouldReproduce();
        void update();
        void checkBorders();
        void draw();
        bool dead();
        void setup();
        void accelerate();
        void decelerate();
};

#endif /* Jammer_h */
