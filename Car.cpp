// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Car.h"
#include "Unit1.h"
#include "Road.h"
#include "Turning.h"
#include "Crossing.h"
#include "PriviligedVehicle.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Car::Car(int xPosition, int yPosition, int direction, int targetVelocity,
	int orientation, String path) {
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->direction = direction;
	this->targetVelocity = targetVelocity;
	this->rate = this->targetVelocity;
	// this->path = "C:\\grafika\\car1.bmp";
	this->path = path;
	this->width = 30;
	this->height = 20;

	this->createImage(xPosition, yPosition, 20, 30, orientation);
}

Car::~Car() {
}

// void Car::checkColission(std::map <int, RoadParticipant*>roadParticipants){
// int tempDistance;
// for(int i=0 ; i<roadParticipants.size() ; i++){
// if((roadParticipants[i]->getXPosition()==this->xPosition)&&(roadParticipants[i]->getYPosition()==this->yPosition)){break;}
//
// if(this->direction==2){if (abs(this->yPosition-roadParticipants[i]->getYPosition())<10) {tempDistance=roadParticipants[i]->getXPosition() - this->getWidth() - this->xPosition;}  }
//
// tempDistance=-tempDistance;
//
// Form1->Label44->Text=this->direction ;
// Form1->Label45->Text=tempDistance ;
// }
//
// if(tempDistance<30&&tempDistance>0){this->rate=0;}
//
//
// }

void Car::update(std::map<int, std::map<int, RoadElement*> >area,
	std::map<int, RoadParticipant *>roadParticipants) {
	RoadElement * temp1;

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

					// }
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
			// RoadParticipant * vehicleTemp;
			//
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][0]->vehicleSlots[1]))
			// { Form1->Label3->Text="C";} else	{ Form1->Label3->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][0]->vehicleSlots[2]))
			// { Form1->Label4->Text="C";} else	{ Form1->Label4->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][0]->vehicleSlots[3]))
			// { Form1->Label5->Text="C";} else	{ Form1->Label5->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][0]->vehicleSlots[4]))
			// { Form1->Label8->Text="C";} else	{ Form1->Label8->Text="N";}
			//
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[0][5]->vehicleSlots[1]))
			// { Form1->Label9->Text="C";} else	{ Form1->Label9->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[0][5]->vehicleSlots[2]))
			// { Form1->Label10->Text="C";} else	{ Form1->Label10->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[0][5]->vehicleSlots[3]))
			// { Form1->Label11->Text="C";} else	{ Form1->Label11->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[0][5]->vehicleSlots[4]))
			// { Form1->Label12->Text="C";} else	{ Form1->Label12->Text="N";}
			//
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][5]->vehicleSlots[1]))
			// { Form1->Label13->Text="C";} else	{ Form1->Label13->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][5]->vehicleSlots[2]))
			// { Form1->Label14 ->Text="C";} else	{ Form1->Label14 ->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][5]->vehicleSlots[3]))
			// { Form1->Label15 ->Text="C";} else	{ Form1->Label15 ->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][5]->vehicleSlots[4]))
			// { Form1->Label16 ->Text="C";} else	{ Form1->Label16 ->Text="N";}
			//
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[10][5]->vehicleSlots[1]))
			// { Form1->Label31->Text="C";} else	{ Form1->Label31->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[10][5]->vehicleSlots[2]))
			// { Form1->Label32 ->Text="C";} else	{ Form1->Label32 ->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[10][5]->vehicleSlots[3]))
			// { Form1->Label33 ->Text="C";} else	{ Form1->Label33 ->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[10][5]->vehicleSlots[4]))
			// { Form1->Label34 ->Text="C";} else	{ Form1->Label34 ->Text="N";}
			//
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][10]->vehicleSlots[1]))
			// { Form1->Label35->Text="C";} else	{ Form1->Label35->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][10]->vehicleSlots[2]))
			// { Form1->Label36 ->Text="C";} else	{ Form1->Label36 ->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][10]->vehicleSlots[3]))
			// { Form1->Label37 ->Text="C";} else	{ Form1->Label37 ->Text="N";}
			// if(vehicleTemp = dynamic_cast<Car*>(this->area[5][10]->vehicleSlots[4]))
			// { Form1->Label38 ->Text="C";} else	{ Form1->Label38 ->Text="N";}

		}
	}

}

bool Car::crossingManager(RoadElement * rEl) {
	// podejmowanie decyzji, czy mo¿na przejechaæ na podstawie znaków i zajêtoœæi skrzyzowania
	// jesli zwraca true, to pojazd jedzie
	int tempSlots[5];
	tempSlots[0] = 0;
	// tempSlots[1]=0;
	// tempSlots[2]=0;
	// tempSlots[3]=0;
	// tempSlots[4]=0;
	RoadParticipant * vehicle;

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

	// Form1->Label7->Text= rEl->sgns[2];
	Form1->Label6->Text = rEl->getSgns()[2];
	// oddzielny przypadek na ka¿dy rodzaj skrzy¿owania

	if (rEl->getType() == 1) {
		switch (rEl->getOrientation()) {
		case 0:
			rEl->setSingleSlot(1, 0);
			break;
		case 90:
			rEl->setSingleSlot(2, 0);
			break;
		case 180:
			rEl->setSingleSlot(3, 0);
			break;
		case 270:
			rEl->setSingleSlot(4, 0);
			break;
		}
	}

	// to raczej spoko do typu 0
	// target: rozwi¹zanie uniwersalne, a wczeœnej dodatkowy switch do zerowania slotów i znaków do odpowiednich typów skrzyzowañ

	switch (this->direction) {

	case 1:

		if (rEl->getSlots()[3] == 2) {
			return false;
		}

		else if (rEl->getSgns()[3] == 0) {
			if ((tempSlots[1] == 0) && (tempSlots[2] == 0) &&
				(tempSlots[4] == 0)) {
				return true;
			}
			else if ((tempSlots[4] == 1) && (rEl->getSgns()[4] == 0)) {
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
			else if ((tempSlots[2] == 1) && (rEl->getSgns()[2] == 1)) {
				return false;
			}
			else {
				return true;
			}
		}
		break;

	case 2:
		if (rEl->getSgns()[4] == 2) {
			return false;
		}

		else if (rEl->getSgns()[4] == 0) {
			if ((tempSlots[1] == 0) && (tempSlots[2] == 0) &&
				(tempSlots[3] == 0)) {
				return true;
			}
			else if ((tempSlots[1] == 1) && (rEl->getSgns()[1] == 0)) {
				return true;
			}
			else if ((tempSlots[2] == 1) && (rEl->getSgns()[2] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}

		else if (rEl->getSgns()[4] == 1) {
			if ((tempSlots[1] == 1) && (rEl->getSgns()[1] == 1)) {
				return false;
			}
			else {
				return true;
			}
		}
		break;
	case 3:
		if (rEl->getSgns()[1] == 2) {
			return false;
		}

		else if (rEl->getSgns()[1] == 0) {
			if ((tempSlots[2] == 0) && (tempSlots[3] == 0) &&
				(tempSlots[4] == 0)) {
				return true;
			}
			else if ((tempSlots[2] == 1) && (rEl->getSgns()[2] == 0)) {
				return true;
			}
			else if ((tempSlots[3] == 1) && (rEl->getSgns()[3] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}

		else if (rEl->getSgns()[1] == 1) {
			if ((tempSlots[4] == 1) && (rEl->getSgns()[4] == 1)) {
				return false;
			}
			else {
				return true;
			}
		}
		break;
	case 4:
		if (rEl->getSgns()[2] == 2) {
			return false;
		}

		else if (rEl->getSgns()[2] == 0) {
			if ((tempSlots[1] == 0) && (tempSlots[3] == 0) &&
				(tempSlots[4] == 0)) {
				return true;
			}

			else if ((tempSlots[3] == 1) && (rEl->getSgns()[3] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}

		else if (rEl->getSgns()[2] == 1) {
			if ((tempSlots[4] == 1) && (rEl->getSgns()[4] == 1)) {
				return false;
			}
			else if ((tempSlots[1] == 1) && (rEl->getSgns()[1] == 1)) {
				return false;
			}
			else {
				return true;
			}
		}
		break;

	}

}
