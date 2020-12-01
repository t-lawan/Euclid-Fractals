//
//  PlantDestroyer.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 23/11/2020.
//

#ifndef PlantDestroyer_h
#define PlantDestroyer_h

#include <stdio.h>
#include "ofMain.h"
#include "DNA.h"
#include "Food.h"
#include "AbstractMovingAgent.h"
#include "Soybean.h"
#include "Sugarcane.h"
class PlantDestroyer : public AbstractMovingAgent {
    public:
        PlantDestroyer(ofVec2f _position, DNA _dna) : AbstractMovingAgent(_position, _dna){
            colour = ofColor::red;
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
        PlantDestroyer reproduce();
        bool shouldReproduce();
        void update();
        void checkBorders();
        void draw();
        bool dead();
        void setup();
        void accelerate();
        void decelerate();
};


#endif /* PlantDestroyer_h */
