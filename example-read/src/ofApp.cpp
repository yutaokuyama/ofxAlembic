#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofBackground(0);

	string path = "metaball1.abc";
	abc.open(path);

	// show all drawable names
	abc.dumpFullnames();
	ofLog() << abc.getMaxTime();
	ofLogToConsole();

	cout << "Alembic::Abc::GetLibraryVersionShort() : " << Alembic::Abc::GetLibraryVersionShort() << endl;
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
		abc.get("/Metaball/MetaballShape", mesh);

		//ofScale(10, 10, 10);

		ofPushMatrix();
		ofScale(0.1, 0.1, 0.1);
		//abc.draw();
		mesh.drawWireframe();
		ofPopMatrix();
		//ofSetColor(255, 0, 0);
	}

	ofSetColor(255, 0, 255);

	ofPushMatrix();
	ofScale(0.1, 0.1, 0.1);
	//abc.draw();
	ofPopMatrix();

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}