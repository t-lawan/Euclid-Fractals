//
//  Pollinator.h
//  Euclid Fractals
//
//  Created by Michael Kuhn on 11/22/20.
//

#ifndef Pollinator_h
#define Pollinator_h

#include <stdio.h>
#include "ofMain.h"
#include "DNA.h"
#include "Food.h"
#include "SimulationObject.h"
#include "AbstractMovingAgent.h"

class Pollinator : public AbstractMovingAgent {
   public:    
    Pollinator(ofVec2f _position, DNA _dna) : AbstractMovingAgent(_position, _dna) {
        colour = ofColor(256, 165, 0);
        MIN_SIZE = 10;
        MAX_SIZE = 15;
        r = MAX_SIZE;
        MIN_REPRODUCTION_RATE = 0.0001;
        MAX_REPRODUCTION_RATE = 0.0005;
        MIN_MUTATION_RATE = 0.1;
        MAX_MUTATION_RATE = 0.2;
        MIN_SPEED = 5;
        MAX_SPEED = 15;
        DETERIORATION_RATE = 0.2;
        IMG_NAME = "fairy.png";
        setup();
    };
    void eat(Food f);
    int isOnFood(Food f);
    int isOnSugarCanes(vector<Sugarcane> sugarcanes);
    int isOnSoybeans(vector<Soybean> soybeans);
    Pollinator reproduce();
    bool shouldReproduce();
    void setup();
    void update();
    void checkBorders();
    void draw();
    bool dead();

    void accelerate();
};
#endif /* Pollinator_hpp */
