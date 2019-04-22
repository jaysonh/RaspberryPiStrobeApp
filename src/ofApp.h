#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void exit();
	
	bool bHide = true;

	ofxColorSlider color1;
	bool strobe=false;
	ofxPanel gui;

	int   strobeRate   = 5;
	float strobeChange = 5.0;
	float lastChange   = 0.0;
	float timeDiff = 0.0;

};

