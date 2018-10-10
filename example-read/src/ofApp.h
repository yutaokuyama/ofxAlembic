#pragma once

#include "ofMain.h"
#include "ofxAlembic.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

	ofxAlembic::Reader abc;
	ofEasyCam cam;
};
