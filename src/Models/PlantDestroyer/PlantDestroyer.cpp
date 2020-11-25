//
//  PlantDestroyer.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 23/11/2020.
//

#include "PlantDestroyer.h"


void PlantDestroyer::eat(Food f){
    vitality += 100;
}

PlantDestroyer PlantDestroyer::reproduce(){
        // Child is exact copy of single parent
        DNA childDNA = dna.copy();
        // Child DNA can mutate
        childDNA.mutate(mutation_rate);
        return PlantDestroyer(position, childDNA);
}

bool PlantDestroyer::shouldReproduce(){
    return ofRandom(0, 1) < reproduction_rate;
}

int PlantDestroyer::isOnFood(Food f){
    vector<ofVec2f> food = f.getFood();
    // Are we touching any food objects?s
    for (int i = 0; i < food.size(); i++) {
      float d = position.distance(food[i]);
      // If we are, juice up our strength!
      if (d <= r) {
        vitality += 100;
        return i;
      }
    }
    return -1;
}


void PlantDestroyer::update() {
  // Simple movement based on perlin noise
    
    float vx = ofMap(ofNoise(xoff), 0, 1, -1 * speed, speed);
    float vy = ofMap(ofNoise(yoff), 0, 1, -1 * speed, speed);
    ofVec2f velocity = ofVec2f(vx, vy);
    xoff += 0.01;
    yoff += 0.01;
    position += velocity;
    // Death always looming
    vitality -= DETERIORATION_RATE;
    checkBorders();
    
}

void PlantDestroyer::setup(){
    img.load(IMG_NAME);
    img.resize(r * 2, r * 2);
}

// Wraparound
void PlantDestroyer::checkBorders() {
    float width = ofGetWidth();
    float height = ofGetHeight();
    if (position.x < -r) position.x = width+r;
    if (position.y < -r) position.y = height+r;
    if (position.x > width+r) position.x = -r;
    if (position.y > height+r) position.y = -r;
}

void PlantDestroyer::draw(){
    // draw agents
    ofSetColor(colour,ofMap(vitality, 0, MAX_HEALTH, 0, 200));
//    ofDrawCircle(position.x, position.y, r);
    img.draw(position);
}

bool PlantDestroyer::dead(){
    if (vitality < 0.0) {
      return true;
    } else {
      return false;
    }
}
