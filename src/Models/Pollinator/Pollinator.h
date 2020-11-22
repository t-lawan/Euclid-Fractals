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

class Pollinator : public SimulationObject {
   public:
    
    float polHealth; // Life timer
    float xoff;
    float yoff;
    // DNA will determine reproductivity_rate, and maxspeed
    float pol_reproduction_rate;
    float pol_r;
    float polMaxSpeed;
    ofVec2f position;
    DNA dna;
    
    Pollinator(ofVec2f _position, DNA _dna);
    void polEat(Food f);
    int polIsOnFood(Food f);
    Pollinator polReproduce();
    bool polShouldReproduce();
    void update();
    void polCheckBorders();
    void draw();
    bool dead();
};
#endif /* Pollinator_hpp */
