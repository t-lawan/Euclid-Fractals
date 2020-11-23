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
            MIN_REPRODUCTION_RATE = 0.00005;
            MAX_REPRODUCTION_RATE = 0.0001;
            MIN_MUTATION_RATE = 0.1;
            MAX_MUTATION_RATE = 0.2;
            MIN_SIZE = 10;
            MAX_SIZE = 20;
        };
        void eat(Food f);
        int isOnFood(Food f);
        Sugarcane reproduce();
        bool shouldReproduce();
        void update();
        void checkBorders();
        void draw();
        bool dead();
};
#endif /* Sugarcane_h */
