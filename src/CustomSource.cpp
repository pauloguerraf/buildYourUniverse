#include "CustomSource.h"
#include "Globals.h"

void CustomSource::setup() {
	name = "Custom FBO Source";
	floor.load("floor.png");

	allocate(ofGetWidth(), ofGetHeight());
	reset();
}

void CustomSource::update() {
	for (int i = 0; i < montanhitas.size(); i++) {
		montanhitas[i].update();
	}
	for (int i = 0; i < elementos.size(); i++) {
		elementos[i].update();
	}
	for (int i = 0; i < casas.size(); i++) {
		casas[i].update();
	}
	for (int i = 0; i < personajes.size(); i++) {
		personajes[i].update();
	}
}

void CustomSource::draw() {
	ofClear(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	floor.draw(0.5*ofGetWidth(), 0.5*ofGetHeight(), ofGetWidth(), ofGetHeight());
	ofSetRectMode(OF_RECTMODE_CORNER);
	for (int i = 0; i < montanhitas.size(); i++) {
		montanhitas[i].draw();
	}
	for (int i = 0; i < elementos.size(); i++) {
		elementos[i].draw();
	}
	for (int i = 0; i < casas.size(); i++) {
		casas[i].draw();
	}
	for (int i = 0; i < personajes.size(); i++) {
		personajes[i].draw();
	}
}

void CustomSource::mousePressed() {
	
}

void CustomSource::mouseDragged() {
	///////////
	if (Globals::personaje == -1 && Globals::casa == -1 && Globals::elemento == -1 && Globals::montanha == -1) {
		for (int i = personajes.size() - 1; i >= 0; i--) {
			if (personajes[i].mouseDragged()) {
				Globals::personaje = i;
				break;
			}
		}
		for (int i = casas.size() - 1; i >= 0; i--) {
			if (casas[i].mouseDragged()) {
				Globals::casa = i;
				break;
			}
		}
		for (int i = elementos.size() - 1; i >= 0; i--) {
			if (elementos[i].mouseDragged()) {
				Globals::elemento = i;
				break;
			}
		}
		for (int i = montanhitas.size() - 1; i >= 0; i--) {
			if (montanhitas[i].mouseDragged()) {
				Globals::montanha = i;
				break;
			}
		}
	}
	else if (Globals::personaje != -1) {
		personajes[Globals::personaje].mouseDragged();
	}
	///////////
	else if (Globals::casa != -1) {
		casas[Globals::casa].mouseDragged();
	}
	/////////
	else if (Globals::elemento != -1){
		elementos[Globals::elemento].mouseDragged();
	}
	/////////
	else if (Globals::montanha != -1) {
		montanhitas[Globals::montanha].mouseDragged();
	}

}

void CustomSource::mouseReleased() {
	for (int i = personajes.size() - 1; i >= 0; i--) {
		if (personajes[i].mouseReleased());
	}
	for (int i = casas.size() - 1; i >= 0; i--) {
		if (casas[i].mouseReleased());
	}
	for (int i = elementos.size() - 1; i >= 0; i--) {
		if (elementos[i].mouseReleased());
	}
	for (int i = montanhitas.size() - 1; i >= 0; i--) {
		if (montanhitas[i].mouseReleased());
	}
	Globals::personaje = -1;
	Globals::casa = -1;
	Globals::elemento = -1;
	Globals::montanha = -1;
}

void CustomSource::reset() {
	dragging = false;
	montanhitas.clear();
	elementos.clear();
	casas.clear();
	personajes.clear();
	for (int i = 0; i < 3; i++) {
		uElement e;
		e.setup("montanhitas" + ofToString(i + 1) + ".png");
		montanhitas.push_back(e);
	}
	for (int i = 0; i < 9; i++) {
		uElement e;
		e.setup("elemento" + ofToString(i + 1) + ".png");
		elementos.push_back(e);
	}
	for (int i = 0; i < 1; i++) {
		uElement e;
		e.setup("casas" + ofToString(i + 1) + ".png");
		casas.push_back(e);
	}
	for (int i = 0; i < 5; i++) {
		uElement e;
		e.setup("personaje" + ofToString(i + 1) + ".png");
		personajes.push_back(e);
	}
}