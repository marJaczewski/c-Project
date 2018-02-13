// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Road.h"

// ---------------------------------------------------------------------------

Road::Road(int xPosition, int yPosition) {
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->path = "C:\\grafika\\road.jpg";
	this->width = 50;
	this->height = 50;
	this->orientation = 0;
	this->createImage(xPosition, yPosition, 50, 50, 0);

}

Road::~Road() {
}

#pragma package(smart_init)
