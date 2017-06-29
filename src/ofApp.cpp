#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	customSource = new CustomSource();
	piMapper.registerFboSource(customSource);
	piMapper.setup();
	ofLog(OF_LOG_NOTICE, "HOLA");
}

//--------------------------------------------------------------
void ofApp::update(){
	piMapper.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0);
	piMapper.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	piMapper.keyPressed(key);
	if (key == ' ' && piMapper.getMode() == 0) {
		customSource->reset();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	piMapper.keyReleased(key);

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (piMapper.getMode() == 0)customSource->mouseDragged();
	else piMapper.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (piMapper.getMode() == 0) {
		customSource->mousePressed();
	}
	else piMapper.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	ofLog(OF_LOG_NOTICE, "mouse_released_general");
	if (piMapper.getMode() == 0)customSource->mouseReleased();
	else piMapper.mouseReleased(x, y, button);
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
