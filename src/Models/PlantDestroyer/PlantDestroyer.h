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
            MIN_SIZE = 15;
            MAX_SIZE = 30;
            MIN_REPRODUCTION_RATE = 0.001;
            MAX_REPRODUCTION_RATE = 0.0037;
            MIN_MUTATION_RATE = 0.1;
            MAX_MUTATION_RATE = 0.2;
            MIN_SIZE = 15;
            MAX_SIZE = 30;
            MIN_SPEED = 0.5;
            MAX_SPEED = 15;
            DETERIORATION_RATE = 0.5;
            IMG_NAME = "destroyer.png";
            
            r = ofMap(dna.genes[0], 0, 1, MIN_SIZE, MAX_SIZE);
            reproduction_rate = ofMap(dna.genes[0], 0, 1, MAX_REPRODUCTION_RATE, MIN_REPRODUCTION_RATE);
            mutation_rate = ofMap(dna.genes[0], 0, 1, MAX_MUTATION_RATE, MIN_MUTATION_RATE);
            setup();
        };
        float MIN_SIZE = 100;
        float MAX_SIZE = 200;
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
