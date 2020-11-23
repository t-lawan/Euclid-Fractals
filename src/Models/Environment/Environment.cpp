//
//  Environment.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#include "Environment.h"

Environment::Environment(int num) : food(num + 1), grid(2, 2) {
    for (int i = 0; i < num; i++) {
        ofVec2f position;
        spawn(SUGARCANE, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        spawn(POLLINATOR, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
//        spawn(AGENT, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        spawn(PLANT, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        spawn(PLANT_DESTROYER, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
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
        case POLLINATOR: {
            Pollinator pollinator = Pollinator(position, dna);
            pollinators.push_back(pollinator);
            break;
        };
        case PLANT: {
            Plant plant = Plant(position,dna);
            plants.push_back(plant);
            break;
        };
        case PLANT_DESTROYER: {
            PlantDestroyer plantDestroyer = PlantDestroyer(position,dna);
            plantDestroyers.push_back(plantDestroyer);
            break;
        };
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
      for (int i = 0; i < plants.size(); i++) {
          plants[i].update();
      }
      for (int i = 0; i < pollinators.size(); i++) {
          pollinators[i].update();
      }
    
    for (int i = 0; i < sugarcanes.size(); i++) {
        sugarcanes[i].update();
    }
    
    for (int i = 0; i < plantDestroyers.size(); i++) {
        plantDestroyers[i].update();
    }
}

// Run the world
void Environment::draw() {
    // Draw grid
    grid.draw();
    // Draw  food
    food.draw();
    // Draw all plants
    drawPlants();
    // Draw Pollinators
    drawPollinators();
    // Draw sugarcane
    drawSugarcane();
    // Draw all plant destroyers
    drawPlantDestroyers();
}


void Environment::drawPollinators(){
    for (int i = 0; i < pollinators.size(); i++) {
      Pollinator pollinator = pollinators[i];
      pollinator.draw();
        // Check if agent is on food
      int index = pollinator.isOnFood(food);
        // If agent is on food. Eat then remove the food item
      if(index > -1) {
          pollinator.eat(index);
          playTick();
          food.remove(index);
      }
      // If it's dead, kill it and make food
      if (pollinator.dead()) {
        playTick();
        food.add(pollinator.position);
        pollinators.erase(pollinators.begin() + i);
      }
      // reproduction check2
        if(pollinator.shouldReproduce()) {
            if (ofRandom(1) < 0.5){
                spawn(SUGARCANE ,pollinator.position.x, pollinator.position.y);
                playTick();
            } else {
                    playTick();
                pollinators.push_back(pollinator.reproduce());
            }
        }
    }
}

void Environment::drawPlants(){
    for (int i = 0; i < plants.size(); i++) {
        Plant plant = plants[i];
        plant.draw();
            // Check if plant is on food
        int index = plant.plantIsOnFood(food);
            // If plant is on food, absorb then remove food
        if(index > -1){
            plant.plantEat(index);
            food.remove(index);
        }
        // If plant dies, remove and make food
        if (plant.dead()) {
            food.add(plant.position);
            plants.erase(plants.begin() + i);
//            plants.push_back(plant.plantReproduce());
        }
        // check for reproduction
        if(plant.plantShouldReproduce()){
            plants.push_back(plant.plantReproduce());
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
            sugarcane.eat(index);
            playTick();
            food.remove(index);
        }
        // If sugarcane dies, remove and make food
        if (sugarcane.dead()) {
            food.add(sugarcane.position);
            playTick();
            sugarcanes.erase(sugarcanes.begin() + i);
//            sugarcanes.push_back(sugarcane.reproduce());
        }
        // check for reproduction
        if(sugarcane.shouldReproduce()){
            playTick();
            sugarcanes.push_back(sugarcane.reproduce());
        }
    }
}

void Environment::drawPlantDestroyers(){
    for (int i = 0; i < plantDestroyers.size(); i++) {
      PlantDestroyer plantDestroyer = plantDestroyers[i];
      plantDestroyer.draw();
        // Check if agent is on food
      int index = plantDestroyer.isOnFood(food);
        // If agent is on food. Eat then remove the food item
      if(index > -1) {
          plantDestroyer.eat(index);
          playTick();
          food.remove(index);
      }
      // If it's dead, kill it and make food
      if (plantDestroyer.dead()) {
          playTick();
        food.add(plantDestroyer.position);
        plantDestroyers.erase(plantDestroyers.begin() + i);
      }
      // Perhaps this bloop would like to make a baby?
        if(plantDestroyer.shouldReproduce()) {
            playTick();
            plantDestroyers.push_back(plantDestroyer.reproduce());
        }
    }
}
