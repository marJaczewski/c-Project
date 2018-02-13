// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PriviligedVehicle.h"

#include "Road.h"
#include "Turning.h"
#include "Crossing.h"
#include "Car.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PriviligedVehicle::PriviligedVehicle(int xPosition, int yPosition,
	int direction, int targetVelocity, int orientation) {
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->direction = direction;
	this->targetVelocity = targetVelocity;
	this->rate = this->targetVelocity;
	this->path = "C:\\grafika\\priviligedVehicle.jpg";
	// this->path = "C:\\grafika\\car2.jpg";
	this->width = 30;
	this->height = 20;

	this->createImage(xPosition, yPosition, 20, 30, orientation);

}

PriviligedVehicle::~PriviligedVehicle() {
}

void PriviligedVehicle::update(std::map<int, std::map<int, RoadElement*> >area,
	std::map<int, RoadParticipant *>roadParticipants) {
	RoadElement * temp1;
	clock_t czas;
	czas = clock() / 300;

	Form1->Label39->Text = UnicodeString(czas);
	int n = 2;

	if (czas % n < n / 2) {
		this->image->Bitmap->LoadFromFile("C:\\grafika\\priviligedVehicle.jpg");
	}
	else {
		this->image->Bitmap->LoadFromFile
			("C:\\grafika\\priviligedVehicle1.jpg");
	}

	// poszukiwanie, elementu, na którym jest dany uczestnik ruchu
	for (int i = 0; i < area.size(); i++) {
		for (int j = 0; j < area[i].size(); j++) {

			if (this->checkArea(area[i][j])) {

				temp1 = area[i][j];
				if (temp1 = dynamic_cast<Road*>(area[i][j])) {
					this->checkColission(roadParticipants);
					this->setChoosenDirection(false);
					this->setStartedCrossing(0);
					this->onCrossing = false;

					this->move();
					break;
				}
				else if (temp1 = dynamic_cast<Turning*>(area[i][j])) {
					this->checkColission(roadParticipants);
					this->turn(area[i][j]);
					break;
				}
				else if (temp1 = dynamic_cast<Crossing*>(area[i][j])) {
					this->checkColission(roadParticipants);
					switch (this->getStartedCrossing()) {
					case 0:

						this->setStartedCrossing(1);
						if (this->choosenDirection == false) {
							this->randomDirection(area[i][j]);
						}
						break;
					case 1:
						area[i][j]->setVehicleSlots(roadParticipants);
						if (this->crossingManager(area[i][j])) {
							this->onCrossing = true;
							this->cross(area[i][j]);
						}
						break;

					}

				}
			}

		}
	}

}

bool PriviligedVehicle::crossingManager(RoadElement * rEl) {
	// podejmowanie decyzji, czy mo¿na przejechaæ na podstawie znaków i zajêtoœæi skrzyzowania
	// jesli zwraca true, to pojazd jedzie

	// ale Priviliged zawsze ma pierwszeñstwo nad zwyk³ym
	// wiec jesli jest tylko jeden to generalnie zawsze true

	return true;

	int tempSlots[5];
	tempSlots[0] = 0;
	RoadParticipant * vehicle;

	//
	// if(vehicle=dynamic_cast<PriviligedVehicle*>(rEl->getVehicles()[1])){tempSlots[1]=2;}else{tempSlots[1]=0;}
	// if(vehicle=dynamic_cast<PriviligedVehicle*>(rEl->getVehicles()[2])){tempSlots[2]=2;}else{tempSlots[2]=0;}
	// if(vehicle=dynamic_cast<PriviligedVehicle*>(rEl->getVehicles()[3])){tempSlots[3]=2;}else{tempSlots[3]=0;}
	// if(vehicle=dynamic_cast<PriviligedVehicle*>(rEl->getVehicles()[4])){tempSlots[4]=2;}else{tempSlots[4]=0;}

	if (vehicle = dynamic_cast<Car*>(rEl->getVehicles()[1])) {
		tempSlots[1] = 1;
	}
	else if (vehicle = dynamic_cast<PriviligedVehicle*>(rEl->getVehicles()[1]))
	{
		tempSlots[1] = 2;
	}
	else {
		tempSlots[1] = 0;
	}
	if (vehicle = dynamic_cast<Car*>(rEl->getVehicles()[2])) {
		tempSlots[2] = 1;
	}
	else if (vehicle = dynamic_cast<PriviligedVehicle*>(rEl->getVehicles()[2]))
	{
		tempSlots[2] = 2;
	}
	else {
		tempSlots[2] = 0;
	}
	if (vehicle = dynamic_cast<Car*>(rEl->getVehicles()[3])) {
		tempSlots[3] = 1;
	}
	else if (vehicle = dynamic_cast<PriviligedVehicle*>(rEl->getVehicles()[3]))
	{
		tempSlots[3] = 2;
	}
	else {
		tempSlots[3] = 0;
	}
	if (vehicle = dynamic_cast<Car*>(rEl->getVehicles()[4])) {
		tempSlots[4] = 1;
	}
	else if (vehicle = dynamic_cast<PriviligedVehicle*>(rEl->getVehicles()[4]))
	{
		tempSlots[4] = 2;
	}
	else {
		tempSlots[4] = 0;
	}

	// oddzielny przypadek na ka¿dy rodzaj skrzy¿owania

	if (rEl->getType() == 1) {
		switch (rEl->getOrientation()) {
		case 0:
			rEl->setSingleSlot(1, 0);
		case 90:
			rEl->setSingleSlot(2, 0);
		case 180:
			rEl->setSingleSlot(3, 0);
		case 270:
			rEl->setSingleSlot(4, 0);
		}
	}

	// target: rozwi¹zanie uniwersalne, a wczeœnej dodatkowy switch do zerowania slotów i znaków do odpowiednich typów skrzyzowañ

	switch (this->direction) {

	case 1:
		if (rEl->getSgns()[3] == 0) {
			if ((tempSlots[1] == 0) && (tempSlots[2] == 0) &&
				(tempSlots[4] == 0)) {
				return true;
			}
			else if ((tempSlots[4] == 2) && (rEl->getSgns()[4] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}

		else if (rEl->getSgns()[3] == 1) {
			if ((tempSlots[1] == 1) && (rEl->getSgns()[1] == 1)) {
				return false;
			}
			else if ((tempSlots[2] == 2) && (rEl->getSgns()[2] == 1)) {
				return false;
			}
			else {
				return true;
			}
		}
		break;

	case 2:
		if (rEl->getSgns()[4] == 0) {
			if ((tempSlots[1] == 0) && (tempSlots[2] == 0) &&
				(tempSlots[3] == 0)) {
				return true;
			}
			else if ((tempSlots[1] == 2) && (rEl->getSgns()[1] == 0)) {
				return true;
			}
			else if ((tempSlots[2] == 2) && (rEl->getSgns()[2] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}

		else if (rEl->getSgns()[4] == 1) {
			if ((tempSlots[1] == 2) && (rEl->getSgns()[1] == 1)) {
				return false;
			}
			else {
				return true;
			}
		}
		break;
	case 3:
		if (rEl->getSgns()[1] == 0) {
			if ((tempSlots[2] == 0) && (tempSlots[3] == 0) &&
				(tempSlots[4] == 0)) {
				return true;
			}
			else if ((tempSlots[2] == 2) && (rEl->getSgns()[2] == 0)) {
				return true;
			}
			else if ((tempSlots[3] == 2) && (rEl->getSgns()[3] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}

		else if (rEl->getSgns()[1] == 1) {
			if ((tempSlots[4] == 2) && (rEl->getSgns()[4] == 1)) {
				return false;
			}
			else {
				return true;
			}
		}
		break;
	case 4:
		if (rEl->getSgns()[2] == 0) {
			if ((tempSlots[1] == 0) && (tempSlots[3] == 0) &&
				(tempSlots[4] == 0)) {
				return true;
			}

			else if ((tempSlots[3] == 2) && (rEl->getSgns()[3] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}

		else if (rEl->getSgns()[2] == 1) {
			if ((tempSlots[4] == 2) && (rEl->getSgns()[4] == 1)) {
				return false;
			}
			else if ((tempSlots[1] == 2) && (rEl->getSgns()[1] == 1)) {
				return false;
			}
			else {
				return true;
			}
		}
		break;

	}

}
