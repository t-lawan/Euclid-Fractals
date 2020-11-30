//
//  Legend.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 23/11/2020.
//

#include "Legend.h"

Legend::Legend(){
    show = false;
    int size = 10;
    plantDestroyerImg.load("virus.png");
    plantDestroyerImg.resize(size, size);
    
    soybeanImg.load("flower.png");
    soybeanImg.resize(size, size);
    
    sugarcaneImg.load("wheat.png");
    sugarcaneImg.resize(size, size);
    
    pollinatorImg.load("fairy.png");
    pollinatorImg.resize(size, size);
    
    foodImg.load("taco.png");
    foodImg.resize(size, size);
}

void Legend::draw(){
    if(show) {
        drawBackground();
        drawIcons();
    }
};
void Legend::update(int _population, int _numberOfDead){
    population = _population;
    numberOfDead = _numberOfDead;
};

void Legend::drawBackground(){
    ofPushMatrix();
    ofTranslate((2 * ofGetWidth()/3), (3 * ofGetHeight()/5));
    ofSetColor(ofColor::slateGrey, 50);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofDrawRectangle(0, 0, (2 * ofGetWidth()/3), ofGetHeight()/2);
    ofPopMatrix();
};

void Legend::drawIcons(){
    ofPushMatrix();
    
    // Plant Destroyer
    ofTranslate((2 * ofGetWidth()/3) + margin, (3 * ofGetHeight()/5) + margin);
    ofSetColor(ofColor::red);
    plantDestroyerImg.draw(0,0);
    ofDrawBitmapString("plant destroyer", spacing, 0);
    
    // Soybean
    ofTranslate(0, spacing);
    ofSetColor(ofColor::burlyWood);
    soybeanImg.draw(0, 0);
    ofDrawBitmapString("soybean", spacing, 0);
    
    // Sugarcane
    ofTranslate(0, spacing);
    ofSetColor(ofColor::yellow);
    sugarcaneImg.draw(0, 0);
    ofDrawBitmapString("sugarcane", spacing,0);
    
    // Pollinator
    ofTranslate(0, spacing);
    ofSetColor(ofColor(256, 165, 0));
    pollinatorImg.draw(0, 0);
    ofDrawBitmapString("pollinator", spacing, 0);
    
    // Food
    ofTranslate(0, spacing);
    ofSetColor(ofColor::orange);
    foodImg.draw(0, 0);
    ofDrawBitmapString("food", spacing, 5);
    
    // Population
    ofTranslate(0, spacing);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("population: " + to_string(population), spacing, 5);
    
    // Number Of Dead
    ofTranslate(0, spacing);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("dead: " + to_string(numberOfDead), spacing, 5);
    ofPopMatrix();
};



void Legend::toggleShow(){
    show = !show;
}
