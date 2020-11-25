//
//  Environment.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#include "Environment.h"

Environment::Environment(int num) : food(num + 1), grid(20, 20) {
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
            //          playTick();
                food.remove(index);
            }
        }
    } else {
        updatePollinators();
        
        updateSugarcane();
        
        updateSoybeans();
        
        updatePlantDestroyers();
    }
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

void Environment::updatePollinators(){
    for (int i = 0; i < pollinators.size(); i++) {
        pollinators[i].update();
        int index = pollinators[i].isOnFood(food);
        // If agent is on food. Eat then remove the food item
        if(index > -1) {
        //          playTick();
            food.remove(index);
        }
    }
}


void Environment::drawPollinators(){
    for (int i = 0; i < pollinators.size(); i++) {
      Pollinator pollinator = pollinators[i];
      pollinator.draw();
      // If it's dead, kill it and make food
      if (pollinator.dead()) {
//        playTick();
        food.add(pollinator.position);
        pollinators.erase(pollinators.begin() + i);
      }
      // reproduction check2
        if(pollinator.shouldReproduce()) {
            float reproductionRandomValue = ofRandom(1);
            if (reproductionRandomValue < 0.25){
                spawn(SUGARCANE ,pollinator.position.x, pollinator.position.y);
            } else if(reproductionRandomValue < 0.5) {
                spawn(SOYBEAN ,pollinator.position.x, pollinator.position.y);
            } else { pollinators.push_back(pollinator.reproduce());
            }
//            playTick();
        }
    }
}



void Environment::updateSugarcane(){
    for (int i = 0; i < sugarcanes.size(); i++) {
        sugarcanes[i].update();
        int index = sugarcanes[i].isOnFood(food);
        // If agent is on food. Eat then remove the food item
        if(index > -1) {
        //          playTick();
            food.remove(index);
        }
    }

}

void Environment::drawSugarcane(){
    for (int i = 0; i < sugarcanes.size(); i++) {
        Sugarcane sugarcane = sugarcanes[i];
        sugarcane.draw();
            // Check if plant is on food
        int index = sugarcane.isOnFood(food);
            // If plant is on food, absorb then remove food
        if(index > -1){
//            playTick();
            food.remove(index);
        }
        // If sugarcane dies, remove and make food
        if (sugarcane.dead()) {
            food.add(sugarcane.position);
//            playTick();
            sugarcanes.erase(sugarcanes.begin() + i);
//            sugarcanes.push_back(sugarcane.reproduce());
        }
        // check for reproduction
        if(sugarcane.shouldReproduce()){
//            playTick();
            sugarcanes.push_back(sugarcane.reproduce());
        }
    }
}

void Environment::updateSoybeans(){
    for (int i = 0; i < soybeans.size(); i++) {
        soybeans[i].update();
        int index = soybeans[i].isOnFood(food);
        // If agent is on food. Eat then remove the food item
        if(index > -1) {
        //          playTick();
            food.remove(index);
        }
    }
}
void Environment::drawSoybeans(){
    for (int i = 0; i < soybeans.size(); i++) {
        Soybean soybean = soybeans[i];
        soybean.draw();
            // Check if plant is on food
        int index = soybean.isOnFood(food);
            // If plant is on food, absorb then remove food
        if(index > -1){
//            playTick();
            
            food.remove(index);
        }
        // If sugarcane dies, remove and make food
        if (soybean.dead()) {
            food.add(soybean.position);
//            playTick();
            soybeans.erase(soybeans.begin() + i);
//            sugarcanes.push_back(sugarcane.reproduce());
        }
        // check for reproduction
        if(soybean.shouldReproduce()){
//            playTick();
            soybeans.push_back(soybean.reproduce());
        }
    }
}

void Environment::updatePlantDestroyers(){
    for (int i = 0; i < plantDestroyers.size(); i++) {
        plantDestroyers[i].update();
        int index = plantDestroyers[i].isOnFood(food);
        // If agent is on food. Eat then remove the food item
        if(index > -1) {
        //          playTick();
            food.remove(index);
        }
    }
}

void Environment::drawPlantDestroyers(){
    for (int i = 0; i < plantDestroyers.size(); i++) {
      PlantDestroyer plantDestroyer = plantDestroyers[i];
      plantDestroyer.draw();
        
      // Check if agent is on food and remove if index > -1
      int index = plantDestroyer.isOnFood(food);
      if(index > -1) {
//          playTick();
          food.remove(index);
      }

      // Check if agent is on food and remove if index > -1
      index = plantDestroyer.isOnSoybeans(soybeans);
      if(index > -1) {
        //          playTick();
          soybeans.erase(soybeans.begin() + index);
      }
        
      index = plantDestroyer.isOnSugarCanes(sugarcanes);
        if(index > -1) {
          //          playTick();
            sugarcanes.erase(sugarcanes.begin() + index);
        }
        
    
      // If it's dead, kill it and make food
      if (plantDestroyer.dead()) {
//          playTick();
        food.add(plantDestroyer.position);
        plantDestroyers.erase(plantDestroyers.begin() + i);
      }
      // Perhaps this bloop would like to make a baby?
        if(plantDestroyer.shouldReproduce()) {
//            playTick();
            plantDestroyers.push_back(plantDestroyer.reproduce());
        }
    }
}

void Environment::drawAgents(){
    for (int i = 0; i < agents.size(); i++) {
      Agent agent = agents[i];
      agent.draw();
        // Check if agent is on food
//      int index = agent.isOnFood(food);
//        // If agent is on food. Eat then remove the food item
//      if(index > -1) {
////          playTick();
//          food.remove(index);
//      }
      // If it's dead, kill it and make food
      if (agent.dead()) {
//          playTick();
        food.add(agent.position);
        agents.erase(agents.begin() + i);
      }
      // Perhaps this bloop would like to make a baby?
        if(agent.shouldReproduce()) {
//            playTick();
            agents.push_back(agent.reproduce());
        }
    }
}
