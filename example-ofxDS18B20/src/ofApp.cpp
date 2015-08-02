#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	nSensors = tempSensor.listDevices();
	if (nSensors == 0) {
		cout << "No DS18B20 sensors found." << endl;
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int j=0; j<nSensors; j++) {
		cout << "[" << j << "] " << tempSensor.getName(j) << ": " << tempSensor.read(j) << " degrees C" 
		<< ", " << ofGetFrameRate() << "Hz" << endl;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}