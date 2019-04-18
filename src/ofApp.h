#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	
public:
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
	void exit();
	
	void strobeSpeedChanged(float &strobeSpeed);

	bool bHide = true;

	ofxFloatSlider strobeSpeed;
	ofxColorSlider color1;
	ofxColorSlider color2;
	bool strobe=false;
	ofxPanel gui;

	float lastStrobe = 0.0;

};

