//
//  Food.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#include "Food.h"

Food::Food(int num){
    for(int i = 0; i < num; i++){
        ofVec2f vector;
        vector.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        
        food.push_back(vector);
    }
    IMG_NAME = "food.png";
    setup();
}

void Food::setup(){
    img.load(IMG_NAME);
    img.resize(20, 20);
}

void Food::add(ofVec2f position) {
    food.push_back(position);
}

void Food::remove(int index) {
    food.erase(food.begin() + index);
}

void Food::update(){
    if (ofRandom(1) < 0.001) {
        ofVec2f vector;
        vector.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));

        food.push_back(vector);
    }
}
 
void Food::draw(){
    if(food.size() > 0) {
        for(int i = 0; i < food.size(); i++) {
            ofVec2f vector = food[i];
            // Draw Food
            ofSetColor(255);
            img.draw(vector.x, vector.y);
//            ofSetRectMode(OF_RECTMODE_CENTER);
//            ofDrawRectangle(vector.x, vector.y, 10, 10);
        }
    }
}

vector<ofVec2f> Food::getFood(){
    return food;
}
