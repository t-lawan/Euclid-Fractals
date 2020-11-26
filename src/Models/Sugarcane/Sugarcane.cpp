//
//  Sugarcane.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 22/11/2020.
//

#include "Sugarcane.h"



void Sugarcane::eat(Food f){
    vitality += 100;
}

Sugarcane Sugarcane::reproduce(){
    // Child is clone of single parent
    DNA childDNA = dna.copy();
    // Child DNA can mutate
    childDNA.mutate(mutation_rate);
    // Sprout child in random adjacent space
    direction = int(ofRandom(8));
    if (direction == north){
        position.y = position.y - r;
    } else if (direction == northEast){
        position.x = position.x + r;
        position.y = position.y - r;
    } else if (direction == east){
        position.x = position.x + r;
    } else if (direction == southEast){
        position.y = position.y + r;
        position.x = position.x + r;
    } else if (direction == south){
        position.y = position.y + r;
    } else if (direction == southWest){
        position.y = position.y + r;
        position.x = position.x - r;
    } else if (direction == west){
        position.x = position.x - r;
    } else if (direction == northWest){
        position.y = position.y - r;
        position.x = position.x - r;
    }
    
    return Sugarcane(position, childDNA);
}

bool Sugarcane::shouldReproduce(){
    return ofRandom(0, 1) < reproduction_rate;
}

int Sugarcane::isOnFood(Food f){
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

void Sugarcane::update() {
    vitality -= DETERIORATION_RATE;
    checkBorders();
}
void Sugarcane::accelerate(){
    
}

void Sugarcane::checkBorders() {
    float width = ofGetWidth();
    float height = ofGetHeight();
    if (position.x < -r) position.x = width+r;
    if (position.y < -r) position.y = height+r;
    if (position.x > width+r) position.x = -r;
    if (position.y > height+r) position.y = -r;
}

void Sugarcane::draw(){
    // draw plants
    ofSetColor(colour, ofMap(vitality, 0, MAX_HEALTH, 0, 200));
//    ofDrawCircle(position.x, position.y, r);
    img.draw(position);
}

void Sugarcane::setup(){
    img.load(IMG_NAME);
    img.resize(r * 2, r * 2);
}

bool Sugarcane::dead(){
    if (vitality < 0.0) {
      return true;
    } else {
      return false;
    }
}
