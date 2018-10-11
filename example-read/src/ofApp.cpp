#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofBackground(0);

	string path = "virus.abc";
	abc.open(path);

	// show all drawable names
	abc.dumpFullnames();
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
		abc.get("/Sphere/SphereShape", mesh);
		mesh.drawWireframe();
	}

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}