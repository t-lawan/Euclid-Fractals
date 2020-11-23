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

class PlantDestroyer : public AbstractMovingAgent {
    public:
        PlantDestroyer(ofVec2f _position, DNA _dna) : AbstractMovingAgent(_position, _dna){
            colour = ofColor::red;
            MIN_REPRODUCTION_RATE = 0.000075;
            MAX_REPRODUCTION_RATE = 0.00015;
            MIN_MUTATION_RATE = 0.1;
            MAX_MUTATION_RATE = 0.2;
            MIN_SIZE = 5;
            MAX_SIZE = 20;
        };
        void eat(Food f);
        int isOnFood(Food f);
        PlantDestroyer reproduce();
        bool shouldReproduce();
        void update();
        void checkBorders();
        void draw();
        bool dead();
};


#endif /* PlantDestroyer_h */
