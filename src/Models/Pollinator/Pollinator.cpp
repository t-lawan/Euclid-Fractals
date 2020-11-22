//
//  Pollinator.cpp
//  Euclid Fractals
//
//  Created by Michael Kuhn on 11/22/20.
//

#include <stdio.h>
# include "Pollinator.h"

Pollinator::Pollinator(ofVec2f _position, DNA _dna) {
    position = _position;
    dna = _dna;
    
    polHealth = ofRandom(100, 200);
    xoff = ofRandom(0, 1000);
    yoff = ofRandom(0, 1000);
    
    // Gene 0 determines maxspeed and reproduction rate
    polMaxSpeed = ofMap(dna.genes[0], 0, 1, 15, 0);
    pol_r = ofMap(dna.genes[0], 0, 1, 5, 15);
    pol_reproduction_rate = ofMap(dna.genes[0], 0, 1, 0.003, 0.001);
}

void Pollinator::polEat(Food f){
    polHealth += 100;
}

Pollinator Pollinator::polReproduce(){
        // Child is exact copy of single parent
        DNA childDNA = dna.copy();
        // Child DNA can mutate
        childDNA.mutate(0.4);
        return Pollinator(position, childDNA);
}

bool Pollinator::polShouldReproduce(){
    return ofRandom(0, 1) < pol_reproduction_rate;
}

int Pollinator::polIsOnFood(Food f){
    vector<ofVec2f> food = f.getFood();
    // Are we touching any food objects?
    for (int i = food.size()-1; i >= 0; i--) {
      ofVec2f foodposition = food[i];
      float d = position.distance(foodposition);
      // If we are, juice up our strength!
      if (d <= pol_r) {
        polHealth += 100;
        return i;
      } else {
          return -1;
      }
    }
}


void Pollinator::update() {
  // Simple movement based on perlin noise
    
    float vx = ofMap(ofNoise(xoff), 0, 1, -1 * polMaxSpeed, polMaxSpeed);
    float vy = ofMap(ofNoise(yoff), 0, 1, -1 * polMaxSpeed, polMaxSpeed);
    ofVec2f velocity = ofVec2f(vx, vy);
    xoff += 0.01;
    yoff += 0.01;
    position += velocity;
    // Death always looming
    polHealth -= 0.2;
    polCheckBorders();
    
}

// Wraparound
void Pollinator::polCheckBorders() {
    float width = ofGetWidth();
    float height = ofGetHeight();
    if (position.x < -pol_r) position.x = width+pol_r;
    if (position.y < -pol_r) position.y = height+pol_r;
    if (position.x > width+pol_r) position.x = -pol_r;
    if (position.y > height+pol_r) position.y = -pol_r;
}

void Pollinator::draw(){
    // draw agents
    ofSetColor(256, 165, 0,ofMap(polHealth, 0, 200, 0, 255));
    ofDrawCircle(position.x, position.y, pol_r);
}

bool Pollinator::dead(){
    if (polHealth < 0.0) {
      return true;
    } else {
      return false;
    }
}
