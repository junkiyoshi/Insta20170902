#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

	this->noise_source = ofRandom(10);
}

//--------------------------------------------------------------
void ofApp::update(){
	this->noise_source -= 0.005;
}

//--------------------------------------------------------------
void ofApp::draw(){

	this->cam.begin();

	float tmp_noise_source = this->noise_source;
	int deg = 0;
	float x, y, pre_x, pre_y;
	ofColor line_color;

	for (int i = 0; i < 255; i += 2) {
		pre_x = 0;
		pre_y = 0;
		ofRotateZ(i / 255 * 360);
		for (int len = 0; len < ofGetWidth() / 2; len += 1) {
			deg = ofNoise(tmp_noise_source) * 720;

			x = len * cos(deg * DEG_TO_RAD);
			y = len * sin(deg * DEG_TO_RAD);

			line_color.setHsb(i, 255, 255);
			ofSetColor(line_color, ofMap(len, ofGetWidth(), 0, 0, 255));
			
			ofLine(pre_x, pre_y, x, y);

			tmp_noise_source += 0.001;

			pre_x = x;
			pre_y = y;
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
