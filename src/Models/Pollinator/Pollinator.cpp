//
//  Pollinator.cpp
//  Euclid Fractals
//
//  Created by Michael Kuhn on 11/22/20.
//

#include <stdio.h>
# include "Pollinator.h"

//Pollinator::Pollinator(ofVec2f _position, DNA _dna) {
//    position = _position;
//    dna = _dna;
//
//    polHealth = ofRandom(100, 200);
//    xoff = ofRandom(0, 1000);
//    yoff = ofRandom(0, 1000);
//
//    // Gene 0 determines maxspeed and reproduction rate
//    polMaxSpeed = ofMap(dna.genes[0], 0, 1, 15, 0);
//    pol_r = ofMap(dna.genes[0], 0, 1, 5, 15);
//    pol_reproduction_rate = ofMap(dna.genes[0], 0, 1, 0.003, 0.001);
//}

void Pollinator::eat(Food f){
    vitality += 100;
}

Pollinator Pollinator::reproduce(){
        // Child is exact copy of single parent
        DNA childDNA = dna.copy();
        // Child DNA can mutate
        childDNA.mutate(0.4);
        return Pollinator(position, childDNA);
}

bool Pollinator::shouldReproduce(){
    return ofRandom(0, 1) < reproduction_rate;
}

int Pollinator::isOnFood(Food f){
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

void Pollinator::accelerate(){
    
}

void Pollinator::decelerate(){
    if(ofRandom(0,1) < ACCELERATION_RATE){
        cout << "Pollinator decelerate" << endl;
        reproduction_rate += 0.0001;
        vitality += 1;
    }
}

void Pollinator::setup(){
    img.load(IMG_NAME);
    img.resize(r * 2, r * 2);
}


void Pollinator::update() {
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

// Wraparound
void Pollinator::checkBorders() {
    float width = ofGetWidth();
    float height = ofGetHeight();
    if (position.x < -r) position.x = width+r;
    if (position.y < -r) position.y = height+r;
    if (position.x > width+r) position.x = -r;
    if (position.y > height+r) position.y = -r;
}

void Pollinator::draw(){
    // draw agents
    ofSetColor(colour,ofMap(vitality, 0, MAX_HEALTH, 0, 200));
//    ofDrawCircle(position.x, position.y, r);
    img.draw(position);
}

bool Pollinator::dead(){
    if (vitality < 0.0) {
      return true;
    } else {
      return false;
    }
}
