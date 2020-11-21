//
//  Food.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#ifndef Food_h
#define Food_h

#include <stdio.h>
#include "ofMain.h"
#include "SimulationObject.h"

class Food : public SimulationObject {
    public:
        vector<ofVec2f> food;

        Food(int num);
        void add(ofVec2f position);
        void remove(int index);
        void draw();
        void update();
        vector<ofVec2f> getFood();
};
#endif /* Food_h */
