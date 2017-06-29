#include "uElement.h"

//--------------------------------------------------------------
void uElement::setup(string fileName_){
	img.load(fileName_);
	col = ofColor(255, 255, 255, 255);
	center = ofPoint(ofRandom(ofGetWidth()), ofGetHeight() / 2);
	ellipseColor = ofColor(255, 0, 0);
	width = img.getWidth()*0.45;
	height = img.getHeight()*0.45;
	moving = false;
	colorSelector.load("colorselector.jpg");
	colorWidth = colorSelector.getWidth();
	colorHeight = colorSelector.getHeight();
	mode = 0;
}

//--------------------------------------------------------------
void uElement::update(){
}

//--------------------------------------------------------------
void uElement::draw(){
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(col);
	img.draw(center, width, height);
	ofSetRectMode(OF_RECTMODE_CORNER);
	if (mode == 1) {
		ofSetColor(255);
		colorSelector.draw(center);
	}
	ofSetColor(ellipseColor);
	ofEllipse(ofGetMouseX(), ofGetMouseY(), 10, 10);
}

//--------------------------------------------------------------
void uElement::toggleMode() {

}

//--------------------------------------------------------------
bool uElement::mousePressed() {
	if (ofGetMouseX() < center.x + width / 2 && ofGetMouseX() > center.x - width / 2 &&
		ofGetMouseY() < center.y + height / 2 && ofGetMouseY() > center.y - height / 2 && !moving) {
		distx = ofGetMouseX() - center.x;
		disty = ofGetMouseY() - center.y;
	}
	return false;
}

//--------------------------------------------------------------
bool uElement::mouseDragged() {
	if (ofGetMouseX() < center.x + width / 2 && ofGetMouseX() > center.x - width / 2 &&
		ofGetMouseY() < center.y + height / 2 && ofGetMouseY() > center.y - height / 2 && moving == false) {
		distx = ofGetMouseX() - center.x;
		disty = ofGetMouseY() - center.y;
		center.x = ofGetMouseX() - distx;
		center.y = ofGetMouseY() - disty;
		moving = true;
		mode = 0;
		return true;
	}
	else if (moving == true) {
		center.x = ofGetMouseX() - distx;
		center.y = ofGetMouseY() - disty;
		mode = 0;
		return true;
	}
	return false;
}

//--------------------------------------------------------------
bool uElement::mouseReleased() {
	if (mode == 1 && ofGetMouseX() < center.x + colorWidth && ofGetMouseX() > center.x  &&
		ofGetMouseY() < center.y + colorHeight && ofGetMouseY() > center.y) {
		ellipseColor = ofColor(255, 255, 0);
		col = colorSelector.getColor(ofGetMouseX() - center.x, ofGetMouseY() - center.y);
		moving = false; 
		ofLog(OF_LOG_NOTICE, "mouse_released_colorselected");

		return true;
	}
	if (mode == 0 && ofGetMouseX() < center.x + width/2 && ofGetMouseX() > center.x - width/2 &&
		ofGetMouseY() < center.y + height/2 && ofGetMouseY() > center.y - height/2){
		mode = 1;
		moving = false;
		ofLog(OF_LOG_NOTICE, "mouse_released_showingcolor");
		return true;
	}
	else {
		mode = 0;
		moving = false;
		return false;
	}
	return false;
}