#include "ofApp.h"
const float EULERS_NUMBER = 1.618282;
const int NUMBER_OF_AGENTS = 5;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowTitle("Intercropping Simulation");    
    ofSetDataPathRoot("../Resources/data/");
    ofBackground(255);
    
    
    ofSetFrameRate(20);
//    ofSetBackgroundAuto(true);
    
    environment = Environment(NUMBER_OF_AGENTS);
//    legend = Legend();
    environment.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    environment.update();
    legend.update(environment.population, environment.numberOfDead);
    barchart.update(environment.sugarcanePopulation(), environment.soybeanPopulation(), environment.plantDestroyerPopulation(), environment.pollinatorPopulation());
}

//--------------------------------------------------------------
void ofApp::draw(){
    environment.draw();
//    drawSpiral();
    legend.draw();
    barchart.draw();
    controls.draw();
}

void ofApp::drawSpiral(){

    ofPushMatrix();
    // Calculate x, y values using sin,cons
    float x = initialRadius * cos(theta);
    float y = initialRadius * sin(theta);
    ofSetColor(0, 100);
//    ofFill();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    line.curveTo(x, y);
    line.draw();
    initialRadius = initialRadius + 0.2;
    theta = theta + 0.01;
    ofNoFill();
    ofPopMatrix();
}

ofVec2f ofApp::getCoordinates(){
    ofVec2f coordinates(0,0);
    if(masterBuilderMode) {
        coordinates.set(ofGetMouseX(), ofGetMouseY());
    } else {
        coordinates.set(ofRandomWidth(), ofRandomHeight());
    }
    
    return coordinates;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == '1'){
        ofVec2f coordinates = getCoordinates();
        environment.spawn(POLLINATOR, coordinates.x, coordinates.y);
    }
    if(key == '2'){
        ofVec2f coordinates = getCoordinates();
        environment.spawn(PLANT_DESTROYER, coordinates.x, coordinates.y);
    }
    if(key == '3'){
        ofVec2f coordinates = getCoordinates();
        environment.spawn(SUGARCANE, coordinates.x, coordinates.y);
    }

    if(key == '4'){
        ofVec2f coordinates = getCoordinates();
        environment.spawn(SOYBEAN, coordinates.x, coordinates.y);
    }
    
    if(key == '5'){
        ofVec2f coordinates = getCoordinates();
        environment.spawn(JAMMER, coordinates.x, coordinates.y);
    }
    
    if(key == 'c'){
        controls.toggleShow();
//        barchart.toggleShow();
    }
    
    if(key == 'l'){
        legend.toggleShow();
        
    }
    
    
    
    if(key == 's'){
        img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        img.save("screenshot_" + to_string(numOfScreenshot) + ".png");
        numOfScreenshot++;
    }
    
    if(key == 'm'){
        masterBuilderMode = !masterBuilderMode;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    environment.spawn(POLLINATOR, x, y);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
