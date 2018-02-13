// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Grass.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Grass::Grass(int xPosition, int yPosition) {
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->path = "C:\\grafika\\grass.jpg";
	this->width = 50;
	this->height = 50;
	this->createImage(xPosition, yPosition, 50, 50, 0);

}

Grass::~Grass() {
}
