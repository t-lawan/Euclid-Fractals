//
//  Environment.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#include "Environment.h"

Environment::Environment(int num) : food(num + 1), grid(4, 4) {
    isTest = false;
    for (int i = 0; i < num; i++) {
        ofVec2f position;
        if(isTest) {
            spawn(AGENT, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        } else {
            spawn(SUGARCANE, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
            spawn(POLLINATOR, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
            spawn(SOYBEAN, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
            spawn(PLANT_DESTROYER, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        }
    }
    
    population = sugarcanes.size() + pollinators.size() + soybeans.size() + plantDestroyers.size();
}

void Environment::spawn(AgentTypeEnum type, float x, float y){
    ofVec2f position;
    position.set(x, y);
    DNA dna = DNA();
    switch (type) {
        case SUGARCANE: {
            Sugarcane sugarcane = Sugarcane(position, dna);
            sugarcanes.push_back(sugarcane);
            break;
        };
        case SOYBEAN: {
            Soybean soybean = Soybean(position,dna);
            soybeans.push_back(soybean);
            break;
        };
        case POLLINATOR: {
            Pollinator pollinator = Pollinator(position, dna);
            pollinators.push_back(pollinator);
            break;
        };
        case PLANT_DESTROYER: {
            PlantDestroyer plantDestroyer = PlantDestroyer(position,dna);
            plantDestroyers.push_back(plantDestroyer);
            break;
        };
        case AGENT: {
            Agent agent = Agent(position, dna);
            agents.push_back(agent);
        }
        default:
            break;
    }

}
void Environment::setup(){
    tick.load("tick.mp3");
    tick.setLoop(false);
    tick.setVolume(0.6);
    
}

void Environment::playTick(){
    tick.play();
}

void Environment::update() {
    food.update();
    if(isTest){
        for (int i = 0; i < agents.size(); i++) {
            agents[i].update();
            int index = agents[i].isOnFood(food);
            // If agent is on food. Eat then remove the food item
            if(index > -1) {
                food.remove(index);
            }
        }
    } else {
        updatePollinators();
        updateSugarcane();
        updateSoybeans();
        updatePlantDestroyers();
    }
    
    grid.update(sugarcanes, soybeans, pollinators);
}

// Run the world
void Environment::draw() {
    // Draw grid
    grid.draw();
    // Draw  food
    food.draw();
    if(isTest) {
        drawAgents();
    } else {
        // Draw Pollinators
        drawPollinators();
        // Draw sugarcane
        drawSugarcane();
        // Draw all plant destroyers
        drawPlantDestroyers();
        // Draw all soybeans
        drawSoybeans();
    }
}


void Environment::agentBorn(){
    population++;
}

void Environment::agentDead(){
    population--;
    numberOfDead++;
}


void Environment::updatePollinators(){
    for (int i = 0; i < pollinators.size(); i++) {
        pollinators[i].update();
        // Check if plant is on food
        int index = pollinators[i].isOnFood(food);
                    // If plant is on food, absorb then remove food
        if(index > -1){
            food.remove(index);
        }
        // reproduction check2
          if(pollinators[i].shouldReproduce()) {
              agentBorn();
              
              float reproductionRandomValue = ofRandom(1);
              if (reproductionRandomValue < 0.3){
                  spawn(SUGARCANE ,pollinators[i].position.x, pollinators[i].position.y);
              } else if(reproductionRandomValue < 0.6) {
                  spawn(SOYBEAN ,pollinators[i].position.x, pollinators[i].position.y);
              } else { pollinators.push_back(pollinators[i].reproduce());
              }
          }
       // If it's dead, kill it and make food
          if (pollinators[i].dead()) {
              agentDead();
            food.add(pollinators[i].position);
            pollinators.erase(pollinators.begin() + i);
          }

        }
}

void Environment::drawPollinators(){
    for (int i = 0; i < pollinators.size(); i++) {
      Pollinator pollinator = pollinators[i];
      pollinator.draw();
    }
}



void Environment::updateSugarcane(){
    for (int i = 0; i < sugarcanes.size(); i++) {
        sugarcanes[i].update();
        // Check if plant is on food
        int index = sugarcanes[i].isOnFood(food);
                    // If plant is on food, absorb then remove food
        if(index > -1){
            food.remove(index);
        }

                // check for reproduction
        if(sugarcanes[i].shouldReproduce()){
                agentBorn();
            sugarcanes.push_back(sugarcanes[i].reproduce());
        }
        
        // If sugarcane dies, remove and make food
        if (sugarcanes[i].dead()) {
            agentDead();
            food.add(sugarcanes[i].position);
            sugarcanes.erase(sugarcanes.begin() + i);
        //            sugarcanes.push_back(sugarcane.reproduce());
        }
    }

}

void Environment::drawSugarcane(){
    for (int i = 0; i < sugarcanes.size(); i++) {
        Sugarcane sugarcane = sugarcanes[i];
        sugarcane.draw();

    }
}

void Environment::updateSoybeans(){
    for (int i = 0; i < soybeans.size(); i++) {
        soybeans[i].update();
                
        // Check if plant is on food
        int index = soybeans[i].isOnFood(food);
                    // If plant is on food, absorb then remove food
        if(index > -1){
            food.remove(index);
        }

                // check for reproduction
        if(soybeans[i].shouldReproduce()){
            agentBorn();
            soybeans.push_back(soybeans[i].reproduce());
        }
        
                // If sugarcane dies, remove and make food
        if (soybeans[i].dead()) {
            agentDead();
            food.add(soybeans[i].position);
            soybeans.erase(soybeans.begin() + i);
        }
    }
}
void Environment::drawSoybeans(){
    for (int i = 0; i < soybeans.size(); i++) {
        Soybean soybean = soybeans[i];
        soybean.draw();

    }
}

void Environment::updatePlantDestroyers(){
    for (int i = 0; i < plantDestroyers.size(); i++) {
        plantDestroyers[i].update();
        int index = plantDestroyers[i].isOnFood(food);
        // If agent is on food. Eat then remove the food item
        if(index > -1) {
            food.remove(index);
        }

        // Check if agent is on food and remove if index > -1
          index = plantDestroyers[i].isOnSoybeans(soybeans);
          if(index > -1) {
              agentDead();
              soybeans.erase(soybeans.begin() + index);
          }
            
          index = plantDestroyers[i].isOnSugarCanes(sugarcanes);
            if(index > -1) {
                agentDead();
                sugarcanes.erase(sugarcanes.begin() + index);
            }
            
          // Perhaps this bloop would like to make a baby?
            if(plantDestroyers[i].shouldReproduce()) {
                agentBorn();
        plantDestroyers.push_back(plantDestroyers[i].reproduce());
            }
        
        // If it's dead, kill it and make food
        if (plantDestroyers[i].dead()) {
            agentDead();
          food.add(plantDestroyers[i].position);
          plantDestroyers.erase(plantDestroyers.begin() + i);
        }
    }
}

void Environment::drawPlantDestroyers() {
    for (int i = 0; i < plantDestroyers.size(); i++) {
      PlantDestroyer plantDestroyer = plantDestroyers[i];
      plantDestroyer.draw();

    }
}

void Environment::drawAgents(){
    for (int i = 0; i < agents.size(); i++) {
      Agent agent = agents[i];
      agent.draw();
      // If it's dead, kill it and make food
      if (agent.dead()) {
          agentDead();
        food.add(agent.position);
        agents.erase(agents.begin() + i);
      }
        
        if(agent.shouldReproduce()) {
            agentBorn();
            agents.push_back(agent.reproduce());
        }
    }
}
