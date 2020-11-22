//
//  Plant.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 20/11/2020.
//

#include "Plant.h"

Plant::Plant(ofVec2f _position, DNA _dna) {
    position = _position;
    dna = _dna;
    
    plantHealth = ofRandom(100, 200);
    
    // Gene 0 determines r
    r = ofMap(dna.genes[0], 0 , 1, 5, 20);
    
    // set directional values
    north = 0;
    northEast = 1;
    east = 2;
    southEast = 3;
    south = 4;
    southWest = 5;
    west = 6;
    northWest = 7;
}

void Plant::plantEat(Food f){
    plantHealth += 100;
}

Plant Plant::plantReproduce(){
    // Child is clone of single parent
    DNA childDNA = dna.copy();
    // Child DNA can mutate
    childDNA.mutate(0.4);
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
    
    return  Plant(position, childDNA);
}

bool Plant::plantShouldReproduce(){
    return ofRandom(0, 1) < 0.001;
}

int Plant::plantIsOnFood(Food f){
    vector<ofVec2f> food = f.getFood();
    // Is plant on food?
    for (int i = food.size()-1; i >= 0; i--){
        ofVec2f foodposition = food[i];
        float d = position.distance(foodposition);
        // if so increase starting health
        if (d < r) {
            plantHealth += 100;
            return i;
        } else {
            return -1;
        }
    }
}

void Plant::update() {
    plantHealth -= 0.2;
    plantCheckBorders();
}

void Plant::plantCheckBorders() {
    float width = ofGetWidth();
    float height = ofGetHeight();
    if (position.x < -r) position.x = width+r;
    if (position.y < -r) position.y = height+r;
    if (position.x > width+r) position.x = -r;
    if (position.y > height+r) position.y = -r;
}

void Plant::draw(){
    // draw plants
    ofSetColor(ofColor::green, ofMap(plantHealth, 0, 200, 0, 255));
    ofDrawCircle(position.x, position.y, r);
}

bool Plant::dead(){
    if (plantHealth < 0.0) {
      return true;
    } else {
      return false;
    }
}
