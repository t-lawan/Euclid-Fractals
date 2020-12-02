//
//  BarChart.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 02/12/2020.
//

#include "BarChart.h"
BarChart::BarChart(){
    int size = 10;
    plantDestroyerImg.load("virus.png");
    plantDestroyerImg.resize(size, size);
    
    soybeanImg.load("flower.png");
    soybeanImg.resize(size, size);
    
    sugarcaneImg.load("wheat.png");
    sugarcaneImg.resize(size, size);
    
    pollinatorImg.load("fairy.png");
    pollinatorImg.resize(size, size);
    
    show = true;
}

void BarChart::draw(){
    if(show) {
//        drawBackground();
        drawBars();
    }
};

void BarChart::update(int _sugarcanePop, int _soybeanPop, int _plantdestroyerPop, int _pollinatorPop)
{
    sugarcanePop = _sugarcanePop;
    soybeanPop = _soybeanPop;
    plantdestroyerPop = _plantdestroyerPop;
    pollinatorPop = _pollinatorPop;
    int popArray[] = {sugarcanePop, soybeanPop, plantdestroyerPop, pollinatorPop};
    
    minPopulation = *(int *) min_element(popArray, popArray + 4);
    maxPopulation = *(int *) max_element(popArray, popArray + 4);
};

void BarChart::drawBackground(){
    ofPushMatrix();
    ofTranslate(0, ofGetHeight() * 0.9);
    ofSetColor(ofColor::slateGrey, 50);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofDrawRectangle(0, 0, ofGetWidth()* 0.2, ofGetHeight() * 0.1);
    ofPopMatrix();
};

void BarChart::drawBars(){
    int alpha = 50;
    float minHeight = 1;
    float maxHeight = ofGetHeight() * 0.08;
    ofPushMatrix();
    
    // Pollinator Pop
    ofTranslate(ofGetWidth()* 0.85, ofGetHeight());
    
    ofSetColor(ofColor::red, alpha);
    float distance = ofMap(plantdestroyerPop, minPopulation, maxPopulation, minHeight, maxHeight);
    ofDrawRectangle(0, 0, spacing, -1 * distance);
    

    
    // Plant Destroyer
    ofTranslate(spacing + margin,0);
    ofSetColor(ofColor::green, alpha);
     distance = ofMap(pollinatorPop, minPopulation, maxPopulation, minHeight, maxHeight);
    
    ofDrawRectangle(0, 0, spacing, -1 * distance);
    
    // Sugarcane
    ofTranslate(spacing + margin,0);
    ofSetColor(ofColor::yellow, alpha);
    distance = ofMap(sugarcanePop, minPopulation, maxPopulation, minHeight,maxHeight);
    ofDrawRectangle(0, 0, spacing, -1 * distance);
    
    // Soybean
    ofTranslate(spacing + margin,0);
    ofSetColor(ofColor::burlyWood, alpha);
    distance = ofMap(soybeanPop, minPopulation, maxPopulation, minHeight, maxHeight);
    ofDrawRectangle(0, 0, spacing, -1 * distance);
    
    ofPopMatrix();
};

void BarChart::toggleShow(){
    show = !show;
}
