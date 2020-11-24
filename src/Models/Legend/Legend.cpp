//
//  Legend.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 23/11/2020.
//

#include "Legend.h"

Legend::Legend(){
    show = false;
}

void Legend::draw(){
    if(show) {
        drawBackground();
        drawIcons();
    }
};

void Legend::drawBackground(){
    ofPushMatrix();
    ofTranslate((2 * ofGetWidth()/3), (2 * ofGetHeight()/3));
    ofSetColor(ofColor::slateGrey, 50);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofDrawRectangle(0, 0, (2 * ofGetWidth()/3), ofGetHeight()/2);
    ofPopMatrix();
};

void Legend::drawIcons(){
    ofPushMatrix();
    
    // Plant Destroyer
    ofTranslate((2 * ofGetWidth()/3) + margin, (2 * ofGetHeight()/3) + margin);
    ofSetColor(ofColor::red);
    ofDrawCircle(0, 0, 5);
    ofDrawBitmapString("plant destroyer", spacing, 2.5);
    
    // Soybean
    ofTranslate(0, spacing);
    ofSetColor(ofColor::burlyWood);
    ofDrawCircle(0, 0, 5);
    ofDrawBitmapString("soybean", spacing, 2.5);
    
    // Sugarcane
    ofTranslate(0, spacing);
    ofSetColor(ofColor::yellow);
    ofDrawCircle(0, 0, 5);
    ofDrawBitmapString("sugarcane", spacing, 2.5);
    
    // Pollinator
    ofTranslate(0, spacing);
    ofSetColor(ofColor(256, 165, 0));
    ofDrawCircle(0, 0, 5);
    ofDrawBitmapString("pollinator", spacing, 2.5);
    
    // Food
    ofTranslate(0, spacing);
    ofSetColor(ofColor::orange);
    ofDrawRectangle(0, 0, 10, 10);
    ofDrawBitmapString("food", spacing, 5);
    
    ofPopMatrix();
};



void Legend::toggleShow(){
    show = !show;
}
