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
        r = MIN_SIZE;
    };
    void eat(Food f);
    int isOnFood(Food f);
    Pollinator reproduce();
    bool shouldReproduce();
    void update();
    void checkBorders();
    void draw();
    bool dead();
};
#endif /* Pollinator_hpp */
