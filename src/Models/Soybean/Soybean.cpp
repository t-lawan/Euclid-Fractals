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
    
    return  Soybean(position, childDNA);
}

bool Soybean::shouldReproduce(){
    return ofRandom(0, 1) < reproduction_rate;
}

int Soybean::isOnFood(Food f){
    vector<ofVec2f> food = f.getFood();
    // Is plant on food?
    for (int i = food.size()-1; i >= 0; i--){
        ofVec2f foodposition = food[i];
        float d = position.distance(foodposition);
        // if so increase starting vitality
        if (d < r) {
            vitality += 100;
            return i;
        } else {
            return -1;
        }
    }
}

void Soybean::update() {
    vitality -= 0.2;
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
    ofSetColor(colour, ofMap(vitality, 0, 200, 0, 200));
    ofDrawCircle(position.x, position.y, r);
}

bool Soybean::dead(){
    if (vitality < 0.0) {
      return true;
    } else {
      return false;
    }
}
