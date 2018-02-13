// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Turning.h"
#include "RoadElement.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Turning::Turning(int xPosition, int yPosition, int orientation) {

	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->orientation = orientation;
	this->path = "C:\\grafika\\turning.jpg";
	this->width = 50;
	this->height = 50;
	this->createImage(xPosition, yPosition, 50, 50, this->orientation);
}

Turning::~Turning() {
}
