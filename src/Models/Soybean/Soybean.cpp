//
//  Soybean.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 23/11/2020.
//

#include "Soybean.h"


void Soybean::eat(Food f){
    vitality += 100;
}

Soybean Soybean::reproduce(){
    // Child is clone of single parent
    DNA childDNA = dna.copy();
    // Child DNA can mutate
    childDNA.mutate(mutation_rate);
    // Sprout child in random adjacent space
    direction = int(ofRandom(8));
    float distance = 2 * r;
    if (direction == north){
        position.y = position.y - distance;
    } else if (direction == northEast){
        position.x = position.x + distance;
        position.y = position.y - distance;
    } else if (direction == east){
        position.x = position.x + distance;
    } else if (direction == southEast){
        position.y = position.y + distance;
        position.x = position.x + distance;
    } else if (direction == south){
        position.y = position.y + distance;
    } else if (direction == southWest){
        position.y = position.y + distance;
        position.x = position.x - distance;
    } else if (direction == west){
        position.x = position.x - distance;
    } else if (direction == northWest){
        position.y = position.y - distance;
        position.x = position.x - distance;
    }
    
    return Soybean(position, childDNA);
}

bool Soybean::shouldReproduce(){
    return ofRandom(0, 1) < reproduction_rate;
}
void Soybean::accelerate(){
    if(ofRandom(0,1) < ACCELERATION_RATE){
        reproduction_rate += 0.0001;
        DETERIORATION_RATE += 0.01;
        dna.mutate(mutation_rate);
    }
}

void Soybean::decelerate(){
    if(ofRandom(0,1) < ACCELERATION_RATE){
        reproduction_rate -= 0.0001;
        DETERIORATION_RATE -= 0.01;
    }
}
int Soybean::isOnFood(Food f){
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

void Soybean::update() {
    vitality -= DETERIORATION_RATE;
    checkBorders();
}

void Soybean::checkBorders() {
    float width = ofGetWidth();
    float height = ofGetHeight();
    if (position.x < -r) position.x = width+r;
    if (position.y < -r) position.y = height+r;
    if (position.x > width+r) position.x = -r;
    if (position.y > height+r) position.y = -r;
}

void Soybean::draw(){
    // draw plants
    ofSetColor(colour, ofMap(vitality, 0, MAX_HEALTH, 100, 200));
//    ofDrawCircle(position.x, position.y, r);
    img.draw(position);
}

void Soybean::setup(){
    img.load(IMG_NAME);
    img.resize(r * 2, r * 2);
}

void Soybean::hasBeenTouched() {
    vitality -= 10;
}

bool Soybean::dead(){
    if (vitality < 0.0) {
      return true;
    } else {
      return false;
    }
}
