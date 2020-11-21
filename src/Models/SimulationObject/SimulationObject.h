//
//  SimulationObject.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 20/11/2020.
//

#ifndef SimulationObject_h
#define SimulationObject_h

#include "ofMain.h"
#include <stdio.h>

class SimulationObject {
    public:
        SimulationObject();
        virtual ~SimulationObject(){}
        virtual void update() = 0;
        virtual void draw() = 0;
};

#endif /* SimulationObject_h */
