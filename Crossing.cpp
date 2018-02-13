// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Crossing.h"
#include "RoadParticipant.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Crossing::Crossing(int xPosition, int yPosition, int orientation, int type,
	int sgn1, int sgn2, int sgn3, int sgn4) {

	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->orientation = orientation;
	this->path = "C:\\grafika\\crossing.jpg";
	this->type = type;

	this->sgns[1] = sgn1;
	this->sgns[2] = sgn2;
	this->sgns[3] = sgn3;
	this->sgns[4] = sgn4;

	this->width = 50;
	this->height = 50;
	this->createImage(xPosition, yPosition, 50, 50, this->orientation);

}

Crossing::~Crossing() {
}
