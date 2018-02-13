// ---------------------------------------------------------------------------

#pragma hdrstop

#include "RoadElement.h"
#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

int RoadElement::getType() {
	return this->type;
}

RoadElement::~RoadElement() {
}

void RoadElement::createSign(int xPosition, int yPosition, int orientation,
	int sgn) {

	TImage * sgnImage = new TImage(Form1);
	sgnImage->Parent = Form1;

	String path;

	if (sgn == 0) {
		path = "C:\\grafika\\ustap.bmp";
	}
	else if (sgn == 1) {
		path = "C:\\grafika\\pierwszenstwo.bmp";
	}

	sgnImage->Bitmap->LoadFromFile(path);
	sgnImage->Position->X = xPosition;
	sgnImage->Position->Y = yPosition;
	sgnImage->Visible = true;

	sgnImage->Height = 25;
	sgnImage->Width = 25;
	sgnImage->RotationAngle = orientation;

}

void RoadElement::setSlots(std::map<int, RoadParticipant *>rP) {
	int posDilatation = 10;
	int safetyDistance = 50;

	this->slots[1] = 0;
	this->slots[2] = 0;
	this->slots[3] = 0;
	this->slots[4] = 0;
	for (int i = 0; i < rP.size(); i++) {
		// uzaleznic jeszcze od etapu przebywania na krzyzówce

		if (rP[i]->getStartedCrossing() == 0) {
			switch (rP[i]->getDirection()) {

			case 4:
				if ((abs(rP[i]->getYPosition()-this->yPosition) < posDilatation)
					&& (rP[i]->getXPosition()-this->xPosition -this->width <
					safetyDistance)) {
					this->slots[2] = 1;
				}
				break;
			case 3:
				if ((abs(this->xPosition - rP[i]->getXPosition()) <
					posDilatation) && (this->yPosition - rP[i]->getHeight()
					-this->yPosition < safetyDistance)) {
					this->slots[1] = 1;
				}
				break;
			case 2: // sprawdzic
				if ((abs(this->yPosition +this->height - rP[i]->getYPosition() -
					rP[i]->getHeight()) < posDilatation) && (this->xPosition -
					rP[i]->getXPosition() - rP[i]->getWidth() < safetyDistance))
				{
					this->slots[4] = 1;
				}
				break;
			case 1:
				if ((abs(this->xPosition +this->width - rP[i]->getXPosition() -
					rP[i]->getWidth()) < posDilatation) &&
					(rP[i]->getYPosition()-this->yPosition -this->height <
					safetyDistance)) {
					this->slots[3] = 1;
				}
				break;
			}

		}
	}
}

void RoadElement::setVehicleSlots(std::map<int, RoadParticipant *>rP) {

	this->vehicleSlots[1] = NULL;
	this->vehicleSlots[2] = NULL;
	this->vehicleSlots[3] = NULL;
	this->vehicleSlots[4] = NULL;
	int posDilatation = 15;
	int safetyDistance = 50;

	for (int i = 0; i < rP.size(); i++) {
		// uzaleznic jeszcze od etapu przebywania na krzyzówce
		if (rP[i]->isOnCrossing() == true) {

			Form1->Label30->Text = rP[i]->getDirection();
			switch (rP[i]->getDirection()) {

			case 4:
				if ((abs(rP[i]->getYPosition()-this->yPosition) < posDilatation)
					&& (rP[i]->getXPosition()-this->xPosition -this->width <
					safetyDistance)) {
					this->vehicleSlots[2] = rP[i];
				}
				break;
			case 3:
				if ((abs(this->xPosition - rP[i]->getXPosition()) <
					posDilatation) && (this->yPosition - rP[i]->getHeight()
					-this->yPosition < safetyDistance)) {
					this->vehicleSlots[1] = rP[i];
				}
				break;
			case 2: // sprawdzic
				if ((abs(this->yPosition +this->height - rP[i]->getYPosition() -
					rP[i]->getHeight()) < posDilatation) && (this->xPosition -
					rP[i]->getXPosition() - rP[i]->getWidth() < safetyDistance))
				{
					this->vehicleSlots[4] = rP[i];
				}
				break;
			case 1:
				if ((abs(this->xPosition +this->width - rP[i]->getXPosition() -
					rP[i]->getWidth()) < posDilatation) &&
					(rP[i]->getYPosition()-this->yPosition -this->height <
					safetyDistance)) {
					this->vehicleSlots[3] = rP[i];
				}
				break;
			}
		}

	}
}

int *RoadElement::getSgns() {
	return this->sgns;
}

void RoadElement::setSingleSlot(int slotNumber, int value) {
	this->slots[slotNumber] = value;
}

int * RoadElement::getSlots() {
	return this->slots;
}

RoadParticipant ** RoadElement::getVehicles() {
	return this->vehicleSlots;
}
