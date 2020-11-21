//
//  Environment.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#include "Environment.h"

Environment::Environment(int num) : food(num + 1), grid(50, 50) {
    for (int i = 0; i < num; i++) {
        ofVec2f position;
        born(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
}

void Environment::born(float x, float y){
    ofVec2f position;
    position.set(x, y);
    DNA dna = DNA();
    Agent agent = Agent(position,dna);
    agents.push_back(agent);
}
void Environment::update() {
    food.update();
      for (int i = 0; i < agents.size(); i++) {
        agents[i].update();
      }
}

// Run the world
void Environment::draw() {
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
    
    grid.draw();
}
