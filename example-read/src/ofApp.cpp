#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofBackground(0);

	string path = "box.abc";
	abc.open(path);

	// show all drawable names
	abc.dumpFullnames();
	ofLog() << abc.getMaxTime();
	ofLogToConsole();
}

//--------------------------------------------------------------
void ofApp::update(){
	float t = fmodf(ofGetElapsedTimef(), abc.getMaxTime());

	// update alemblic reader with time in sec
	abc.setTime(t);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(20);
	ofEnableDepthTest();

	cam.begin();
	{
		ofMesh mesh;
		abc.get("/Cube/CubeShape", mesh);

		//ofScale(10, 10, 10);
		ofSetColor(255, 0, 0);
		mesh.drawWireframe();
	}

	ofSetColor(255, 0, 255);

	abc.draw();

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}