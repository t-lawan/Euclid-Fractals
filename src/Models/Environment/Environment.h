//
//  Environment.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#ifndef Environment_h
#define Environment_h

#include <stdio.h>
#include "DNA.h"
#include "Food.h"
#include "Agent.h"
#include "Grid.h"

class Environment {
    public:
        Environment(int num);
        vector<Agent> agents;
        Food food;
        Grid grid;
        void born(float x, float y);
        void update();
        void draw();
};
#endif /* Environment_h */
