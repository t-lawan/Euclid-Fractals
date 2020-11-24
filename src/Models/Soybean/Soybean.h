//
//  Soybean.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 23/11/2020.
//

#ifndef Soybean_h
#define Soybean_h

#include <stdio.h>
#include "ofMain.h"
#include "DNA.h"
#include "Food.h"
#include "AbstractStaticAgent.h"

class Soybean : public AbstractStaticAgent {
    public:
        Soybean(ofVec2f _position, DNA _dna) : AbstractStaticAgent(_position, _dna){
            colour = ofColor::burlyWood;
            MIN_REPRODUCTION_RATE = 0.000075;
            MAX_REPRODUCTION_RATE = 0.0002;
            MIN_MUTATION_RATE = 0.1;
            MAX_MUTATION_RATE = 0.2;
            MIN_SIZE = 10;
            MAX_SIZE = 20;
            DETERIORATION_RATE = 0.2;
            IMG_NAME = "flower.png";
        };
        void eat(Food f);
        int isOnFood(Food f);
        Soybean reproduce();
        bool shouldReproduce();
        void update();
        void checkBorders();
        void draw();
        bool dead();
        void setup();
};

#endif /* Soybean_h */
