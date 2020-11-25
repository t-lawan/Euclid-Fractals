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
#include "PlantDestroyer.h"
#include "Pollinator.h"
#include "Sugarcane.h"
#include "Soybean.h"
#include "AgentTypeEnum.h"

class Environment {
    public:
        Environment(int num);
        bool isTest;
        vector<Agent> agents;
        vector<Sugarcane> sugarcanes;
        vector<Soybean> soybeans;
        vector<Pollinator> pollinators;
        vector<PlantDestroyer> plantDestroyers;
        Food food;
        Grid grid;
        void spawn(AgentTypeEnum type, float x, float y);
        void setup();
        void update();
        void draw();
    
        void updatePollinators();
        void drawPollinators();
    
        void updatePlantDestroyers();
        void drawPlantDestroyers();
    
        void updateSugarcane();
        void drawSugarcane();
    
        void updateSoybeans();
        void drawSoybeans();
    
        void updateAgents();
        void drawAgents();
        
        void playTick();
        ofSoundPlayer tick;
};
#endif /* Environment_h */
