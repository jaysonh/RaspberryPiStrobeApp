#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

	gui.setup(); // most of the time you don't need a name
	gui.add(color1.setup("color1", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
	

	gui.loadFromFile("settings.xml");

	showGUI = false;

	ofHideCursor();

	ofSetFrameRate(strobeRate);
}




//--------------------------------------------------------------
void ofApp::update()
{
	float currTime = ofGetElapsedTimef();
	timeDiff = currTime - lastChange;

	if(timeDiff > strobeChange)
	{
		lastChange  = ofGetElapsedTimef();
		int randTime = (int)ofRandom(0,4);
		switch(randTime)
		{
			case 0:
				strobeChange = 5.0;
				break;
			case 1:
				strobeChange = 10.0;
				break;
			case 2:
				strobeChange = 15.0;
				break;
			case 3:
				strobeChange = 25.0;
				break;
		}

		strobeRate = ofRandom(5,35);
		ofSetFrameRate(strobeRate);

	}	
}

//--------------------------------------------------------------
void ofApp::draw(){
    	
	if(strobe || showGUI)
		ofSetColor(color1);
	else
		ofSetColor(ofColor::black);

	ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
	if(showGUI)
	{
		ofSetFrameRate(60);
		ofShowCursor();
		gui.draw();

		ofSetColor(ofColor::white);
		ofDrawBitmapString("strobeChange: "  + ofToString(timeDiff) + "/" + ofToString(strobeChange), 20,350);
		ofDrawBitmapString("strobeRate:   "  + ofToString(strobeRate),   20, 375);
		
	}else
	{
		ofSetFrameRate(strobeRate);
		ofHideCursor();
	}

	strobe = !strobe;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == '\t')
	{
		showGUI = !showGUI;
	}
	
}



void ofApp::exit()
{

	gui.saveToFile("settings.xml");
}
