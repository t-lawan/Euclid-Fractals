#pragma once

#include "ofMain.h"
#include "DNA.h"
#include "Food.h"
#include "Agent.h"
#include "Plant.h"
#include "Pollinator.h"
#include "Environment.h"
#include "Legend.h"

class ofApp : public ofBaseApp{

	public:
        Environment environment = Environment(1);
        Legend legend = Legend();
        float initialRadius = 0.0;
        float theta = 0.0;
    
        ofPolyline line;
    
        void drawSpiral();
        void drawBranch(float length);
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
