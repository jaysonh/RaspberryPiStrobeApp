#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

	// we add this listener before setting up so the initial circle resolution is correct
	strobeSpeed.addListener(this, &ofApp::strobeSpeedChanged);

	gui.setup(); // most of the time you don't need a name
	gui.add(strobeSpeed.setup("strobeSpeed", 1.0, 0.0, 2.5));
	gui.add(color1.setup("color1", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
	gui.add(color2.setup("color2", ofColor(100, 0, 140), ofColor(0, 0), ofColor(255, 255)));
	

	gui.loadFromFile("settings.xml");

	bHide = true;

}


//--------------------------------------------------------------
void ofApp::strobeSpeedChanged(float &strobeSpeed){
	
}


//--------------------------------------------------------------
void ofApp::update()
{
	float currTime = ofGetElapsedTimef();
	float timeDiff = currTime - lastStrobe;

	if(timeDiff > strobeSpeed)
	{
		strobe = !strobe;

		lastStrobe = currTime + (timeDiff - strobeSpeed);
	}	
}

//--------------------------------------------------------------
void ofApp::draw(){
    
	if(strobe)
		ofSetColor(color1);
	else
		ofSetColor(color2);
	ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
	if(!bHide){
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == '\t')
	{
		bHide = !bHide;
	}
	
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

void ofApp::exit()
{

	gui.saveToFile("settings.xml");
}
