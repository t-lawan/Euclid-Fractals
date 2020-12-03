//
//  Legend.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 23/11/2020.
//

#include "Legend.h"

Legend::Legend(){
    show = false;
    int size = 20;
    plantDestroyerImg.load("destroyer.png");
    plantDestroyerImg.resize(size, size);
    
    soybeanImg.load("soy.png");
    soybeanImg.resize(size, size);
    
    sugarcaneImg.load("cane.png");
    sugarcaneImg.resize(size, size);
    
    pollinatorImg.load("pollinator.png");
    pollinatorImg.resize(size, size);
    
    foodImg.load("food.png");
    foodImg.resize(size, size);
    
    capitalImg.load("capital.png");
    capitalImg.resize(size, size);
    
    fungiImg.load("fungi.png");
    fungiImg.resize(size, size);
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
    ofSetColor(255);
    plantDestroyerImg.draw(0,0);
    
    ofSetColor(0);
    ofDrawBitmapString("plant destroyer", spacing, 0);
    
    // Soybean
    ofTranslate(0, spacing);
    ofSetColor(255);
    soybeanImg.draw(0, 0);
    ofSetColor(0);
    ofDrawBitmapString("soybean", spacing, 0);
    
    // Sugarcane
    ofTranslate(0, spacing);
    ofSetColor(255);
    sugarcaneImg.draw(0, 0);
    ofSetColor(0);
    ofDrawBitmapString("sugarcane", spacing,0);
    
    // Pollinator
    ofTranslate(0, spacing);
    ofSetColor(255);
    pollinatorImg.draw(0, 0);
    ofSetColor(0);
    ofDrawBitmapString("p0llin8.tor", spacing, 0);
    
    // Alien Fungi
    ofTranslate(0, spacing);
    ofSetColor(255);
    fungiImg.draw(0, 0);
    ofSetColor(0);
    ofDrawBitmapString("alien fungi", spacing, 5);
    
    //capillatastrain OXX552
    ofTranslate(0, spacing);
    ofSetColor(255);
    capitalImg.draw(0, 0);
    ofSetColor(0);
    ofDrawBitmapString("capillatastrain OXX552", spacing, 5);
    
    // Food
    ofTranslate(0, spacing);
    ofSetColor(255);
    foodImg.draw(0, 0);
    ofSetColor(0);
    ofDrawBitmapString("food", spacing, 5);
    
    // Population
    ofTranslate(-spacing, spacing);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("population: " + to_string(population), spacing, 5);
    
    // Number Of Dead
    ofTranslate(spacing * 3.5, 0);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("dead: " + to_string(numberOfDead), spacing, 5);
    ofPopMatrix();
};



void Legend::toggleShow(){
    show = !show;
}
