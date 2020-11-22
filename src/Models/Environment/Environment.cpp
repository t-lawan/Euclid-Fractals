//
//  Environment.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#include "Environment.h"

Environment::Environment(int num) : food(num + 1), grid(4, 4) {
    for (int i = 0; i < num; i++) {
        ofVec2f position;
        born(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        germinate(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
}

void Environment::born(float x, float y){
    ofVec2f position;
    position.set(x, y);
    DNA dna = DNA();
    Agent agent = Agent(position,dna);
    agents.push_back(agent);
}

void Environment::germinate(float x, float y){
    ofVec2f position;
    position.set(x, y);
    DNA dna = DNA();
    Plant plant = Plant(position, dna);
    plants.push_back(plant);
}

void Environment::spawn(float x, float y){
    ofVec2f position;
    position.set(x, y);
    DNA dna = DNA();
    Pollinator pollinator = Pollinator(position, dna);
    pollinators.push_back(pollinator);
}


void Environment::update() {
    food.update();
      for (int i = 0; i < agents.size(); i++) {
        agents[i].update();
      }
      for (int i = 0; i < plants.size(); i++) {
          plants[i].update();
      }
      for (int i = 0; i < pollinators.size(); i++) {
          pollinators[i].update();
      }
}

// Run the world
void Environment::draw() {
    // Draw grid
  grid.draw();
    
    // Draw  food
  food.draw();
  
    // Draw all agents
  for (int i = 0; i < agents.size(); i++) {
    Agent agent = agents[i];
    agent.draw();
      // Check if agent is on food
    int index = agent.isOnFood(food);
      // If agent is on food. Eat then remove the food item
    if(index > -1) {
        agent.eat(index);
        food.remove(index);
    }
    // If it's dead, kill it and make food
    if (agent.dead()) {

      food.add(agent.position);
      agents.erase(agents.begin() + i);
    }
    // Perhaps this bloop would like to make a baby?
      if(agent.shouldReproduce()) {
          agents.push_back(agent.reproduce());
      }
  }
    // Draw all plants
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
            plants.push_back(plant.plantReproduce());
        }
        // check for reproduction
        if(plant.plantShouldReproduce()){
            plants.push_back(plant.plantReproduce());
        }
    }
    // Draw Pollinators
    for (int i = 0; i < pollinators.size(); i++) {
      Pollinator pollinator = pollinators[i];
      pollinator.draw();
        // Check if agent is on food
      int index = pollinator.polIsOnFood(food);
        // If agent is on food. Eat then remove the food item
      if(index > -1) {
          pollinator.polEat(index);
          food.remove(index);
      }
      // If it's dead, kill it and make food
      if (pollinator.dead()) {

        food.add(pollinator.position);
        pollinators.erase(pollinators.begin() + i);
      }
      // reproduction check2
        if(pollinator.polShouldReproduce()) {
            if (ofRandom(1) < 0.5){
                germinate(pollinator.position.x, pollinator.position.y);
            } else {
                pollinators.push_back(pollinator.polReproduce());
            }
        }
    }
}
