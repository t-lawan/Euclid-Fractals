//
//  Controls.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 28/11/2020.
//

#include "Controls.h"

Controls::Controls(){
    int size = 20;
    plantDestroyerImg.load("destroyer.png");
    plantDestroyerImg.resize(size, size);
    
    soybeanImg.load("soy.png");
    soybeanImg.resize(size, size);
    
    sugarcaneImg.load("cane.png");
    sugarcaneImg.resize(size, size);
    
    pollinatorImg.load("pollinator.png");
    pollinatorImg.resize(size, size);
    
    show = true;
}

void Controls::draw(){
    if(show) {
        drawBackground();
        drawInstructions();
    }
};

void Controls::drawInstructions(){
    
    ofPushMatrix();
    
    ofTranslate((2 * ofGetWidth()/3), margin);
//    ofTranslate(0, margin);
    
    // Title
    ofTranslate(margin, 0);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("Controls", 0, 0);
    
    // Pollinator
    ofTranslate(0, spacing);
    ofSetColor(255);
    pollinatorImg.draw(0,0);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("1", spacing, margin/2);
    
    // Plant Destroyer
    ofTranslate(0, spacing);
    ofSetColor(255);
    plantDestroyerImg.draw(0,0);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("2", spacing, margin/2);
    
    // Sugarcane
    ofTranslate(0, spacing);
    ofSetColor(255);
    sugarcaneImg.draw(0,0);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("3", spacing, margin/2);

    // Soybean
    ofTranslate(0, spacing);
    ofSetColor(255);
    soybeanImg.draw(0,0);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("4", spacing, margin/2);
    
    // Legend
    ofTranslate(0, spacing);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("Toggle Legend", 0, 0);
    ofDrawBitmapString("l", textSpacing, 0);
    
    // Controls
    ofTranslate(0, spacing);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("Toggle Controls", 0,0);
    ofDrawBitmapString("c", textSpacing, 0);

    // Master Builder
    ofTranslate(0, spacing);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("Master Builder", 0, 0);
    ofDrawBitmapString("m", textSpacing, 0);
    
    
    
    ofPopMatrix();
}

void Controls::drawBackground(){
    ofPushMatrix();
//    ofTranslate(0,0);
    ofTranslate((2 * ofGetWidth()/3), 0);
    ofSetColor(ofColor::slateGrey, 50);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofDrawRectangle(0, 0, (2 * ofGetWidth()/3), ofGetHeight()/2);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()/10);
    ofPopMatrix();
};

void Controls::toggleShow(){
    show = !show;
}
