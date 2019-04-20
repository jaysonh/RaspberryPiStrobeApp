#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

	gui.setup(); // most of the time you don't need a name
	gui.add(color1.setup("color1", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
	gui.add(color2.setup("color2", ofColor(100, 0, 140), ofColor(0, 0), ofColor(255, 255)));
	

	gui.loadFromFile("settings.xml");

	bHide = true;

	ofHideCursor();

}




//--------------------------------------------------------------
void ofApp::update()
{
	float currTime = ofGetElapsedTimef();
	float timeDiff = currTime - lastChange;

	if(timeDiff > strobeChange)
	{
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

		cout << "frameRate: " << strobeRate << " strobe time: " << strobeChange << endl;
	}	
}

//--------------------------------------------------------------
void ofApp::draw(){
    	cout << "frameRate: " << ofGetFrameRate() << endl;
	if(strobe)
		ofSetColor(color1);
	else
		ofSetColor(color2);

	ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
	if(!bHide){
		ofShowCursor();
		gui.draw();
		
	}else
	{
		ofHideCursor();
	}

	strobe = !strobe;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == '\t')
	{
		bHide = !bHide;
	}
	
}



void ofApp::exit()
{

	gui.saveToFile("settings.xml");
}
