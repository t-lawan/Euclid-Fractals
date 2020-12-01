//
//  Jammer.cpp
//  Euclid Fractals
//
//  Created by Michael Kuhn on 12/1/20.
//

#include "Jammer.h"

void Jammer::eat(Food f){
    //vitality += 100;
}

Jammer Jammer::reproduce(){
        // Child is exact copy of single parent
        DNA childDNA = dna.copy();
        // Child DNA can mutate
        childDNA.mutate(mutation_rate);
        return Jammer(position, childDNA);
}

bool Jammer::shouldReproduce(){
    //return ofRandom(0, 1) < reproduction_rate;
}

int Jammer::isOnFood(Food f){
    /*vector<ofVec2f> food = f.getFood();
    // Are we touching any food objects?s
    for (int i = 0; i < food.size(); i++) {
      float d = position.distance(food[i]);
      // If we are, juice up our strength!
      if (d <= r) {
        vitality += 100;
        return i;
      }
    }
    return -1;*/
}

int Jammer::isOnSugarCanes(vector<Sugarcane> sugarcanes){
    // Are we touching any food objects?s
    /*for (int i = 0; i < sugarcanes.size(); i++) {
      float d = position.distance(sugarcanes[i].position);
      // If we are, juice up our strength!
      if (d <= r) {
        vitality += 10;
        return i;
      }
    }
    return -1;*/
}

void Jammer::accelerate(){
    
}

void Jammer::decelerate(){

}

int Jammer::isOnSoybeans(vector<Soybean> soybeans){
    // Are we touching any food objects?s
    /*for (int i = 0; i < soybeans.size(); i++) {
      float d = position.distance(soybeans[i].position);
      // If we are, juice up our strength!
      if (d <= r) {
        vitality += 10;
        return i;
      }
    }
    return -1;*/
}

void Jammer::setup(){
    // no image necessary
    //img.load(IMG_NAME);
    //img.resize(r * 2, r * 2);
}

void Jammer::update(){
    // Simple movement based on perlin noise
      
      float vx = ofMap(ofNoise(xoff), 0, 1, -1 * speed, speed);
      float vy = ofMap(ofNoise(yoff), 0, 1, -1 * speed, speed);
      ofVec2f velocity = ofVec2f(vx, vy);
      xoff += 0.01;
      yoff += 0.01;
      position += velocity;
      // Death not always looming
      //vitality -= DETERIORATION_RATE;
      checkBorders();
}

// Wraparound
void Jammer::checkBorders() {
    float width = ofGetWidth();
    float height = ofGetHeight();
    if (position.x < -r) position.x = width+r;
    if (position.y < -r) position.y = height+r;
    if (position.x > width+r) position.x = -r;
    if (position.y > height+r) position.y = -r;
}

void Jammer::draw(){
    // draw agents
    ofSetColor(colour.purple, 5);
    ofDrawCircle(position.x, position.y, r/2);
}


bool Jammer::dead(){
    /*if (vitality < 0.0) {
      return true;
    } else {
      return false;
    }*/
}
