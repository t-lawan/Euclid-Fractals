//
//  Sugarcane.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 22/11/2020.
//

#ifndef Sugarcane_h
#define Sugarcane_h

#include <stdio.h>
#include "ofMain.h"
#include "DNA.h"
#include "Food.h"
#include "AbstractStaticAgent.h"

class Sugarcane : public AbstractStaticAgent {
    public:
        Sugarcane(ofVec2f _position, DNA _dna) : AbstractStaticAgent(_position, _dna){
            colour = ofColor::yellow;
            MIN_REPRODUCTION_RATE = 0.0005;
            MAX_REPRODUCTION_RATE = 0.0035;
            MIN_MUTATION_RATE = 0.1;
            MAX_MUTATION_RATE = 0.2;
            MIN_SIZE = 20;
            MAX_SIZE = 30;
            DETERIORATION_RATE = 0.2;
            IMG_NAME = "cane.png";
            
            r = ofMap(dna.genes[0], 0, 1, MIN_SIZE, MAX_SIZE);
            reproduction_rate = ofMap(dna.genes[0], 0, 1, MAX_REPRODUCTION_RATE, MIN_REPRODUCTION_RATE);
            mutation_rate = ofMap(dna.genes[0], 0, 1, MAX_MUTATION_RATE, MIN_MUTATION_RATE);
            
            setup();
        };
        void eat(Food f);
        int isOnFood(Food f);
        Sugarcane reproduce();
        bool shouldReproduce();
        void update();
        void checkBorders();
        void draw();
    void hasBeenTouched();
        bool dead();
        void setup();
        void accelerate();
        void decelerate();
};
#endif /* Sugarcane_h */
