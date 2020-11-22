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
#include "Plant.h"
#include "Pollinator.h"
#include "Sugarcane.h"
#include "AgentTypeEnum.h"

class Environment {
    public:
        Environment(int num);
        vector<Agent> agents;
        vector<Plant> plants;
        vector<Sugarcane> sugarcanes;
        vector<Pollinator> pollinators;
        Food food;
        Grid grid;
        void born(float x, float y);
        void germinate(float x, float y);
        void spawn(AgentTypeEnum type, float x, float y);
        void update();
        void draw();
        void drawAgents();
        void drawPlants();
        void drawPollinators();
        void drawSugarcane();
};
#endif /* Environment_h */
