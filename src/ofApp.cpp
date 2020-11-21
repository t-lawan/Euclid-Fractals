#include "ofApp.h"
const float EULERS_NUMBER = 1.618282;
const int NUMBER_OF_AGENTS = 2;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(20);
    ofSetBackgroundAuto(true);
    
    environment = Environment(NUMBER_OF_AGENTS);
}

//--------------------------------------------------------------
void ofApp::update(){
    environment.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    environment.update();
    environment.draw();
//    drawSpiral();
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

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    environment.born(x, y);
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