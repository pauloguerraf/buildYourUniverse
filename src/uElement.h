#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

class uElement {

	public:
		void setup(string s_);
		void update();
		void draw();
		//void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
		void toggleMode();
		bool mousePressed();
		bool mouseDragged();
		bool mouseReleased();

		ofImage img;
		ofImage colorSelector;
		float colorWidth;
		float colorHeight;
		float distx;
		float disty;

		ofColor col;
		ofPoint center;
		ofColor ellipseColor;
		float width;
		float height;
		//ofxDatGui* gui;
		bool mode;
		bool moving;
};
