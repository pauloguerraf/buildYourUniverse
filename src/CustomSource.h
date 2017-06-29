#pragma once

#include "ofMain.h"
#include "FboSource.h"
#include "ofxDatGui.h"
#include "uElement.h"

class CustomSource : public ofx::piMapper::FboSource {
public:
	void setup();
	void update();
	void draw();
	void mousePressed();
	void mouseDragged();
	void mouseReleased();
	void reset();
	bool dragging;


	vector<uElement> montanhitas;
	vector<uElement> elementos;
	vector<uElement> casas;
	vector<uElement> personajes;
	ofColor col;
	ofImage colorSelector;


	//illustration
	ofImage floor;
};