// ---------------------------------------------------------------------------

#pragma hdrstop
#include<iostream>
#include "Simulation.h"
#include "RoadElement.h"

#include "Road.h"
#include "Turning.h"
#include "Grass.h"
#include "Crossing.h"
#include "Car.h"
#include "PriviligedVehicle.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)

// Simulation::Simulation(int top, int left, std::map <int, std::map <int, RoadElement* > > area,  std::map <int, RoadParticipant* > roadParticipants ){
// this->top=top;
// this->left=left;
// this->area=area;
// this->roadParticipants=roadParticipants;
// }

Simulation::Simulation(int top, int left) {
	this->top = top;
	this->left = left;
	this->run = true;

}

void Simulation::drawSigns(std::map<int, std::map<int, RoadElement*> >area) {
	for (int i = 0; i < area.size(); i++) {
		for (int j = 0; j < area[i].size(); j++) {
			RoadElement * roadElement;
			if (roadElement = dynamic_cast<Crossing*>(area[i][j])) {
				if (area[i][j]->getType() == 1) {
					switch (area[i][j]->getOrientation()) {
					case 0:
						area[i][j]->createSign(area[i][j]->getXPosition() - 25,
							area[i][j]->getYPosition() + 12, 90,
							area[i][j]->getSgns()[4]);
						area[i][j]->createSign(area[i][j]->getXPosition() + 12,
							area[i][j]->getYPosition() + area[i][j]->getWidth(),
							0, area[i][j]->getSgns()[3]);
						area[i][j]->createSign(area[i][j]->getXPosition() +
							area[i][j]->getWidth(),
							area[i][j]->getYPosition() + 12, 270,
							area[i][j]->getSgns()[2]);
						break;
					case 270:
						area[i][j]->createSign(area[i][j]->getXPosition() + 12,
							area[i][j]->getYPosition() - 25, 180,
							area[i][j]->getSgns()[1]);
						area[i][j]->createSign(area[i][j]->getXPosition() + 12,
							area[i][j]->getYPosition() + area[i][j]->getWidth(),
							0, area[i][j]->getSgns()[3]);
						area[i][j]->createSign(area[i][j]->getXPosition() +
							area[i][j]->getWidth(),
							area[i][j]->getYPosition() + 12, 270,
							area[i][j]->getSgns()[2]);
						break;
					case 90:
						area[i][j]->createSign(area[i][j]->getXPosition() + 12,
							area[i][j]->getYPosition() - 25, 180,
							area[i][j]->getSgns()[1]);
						area[i][j]->createSign(area[i][j]->getXPosition() + 12,
							area[i][j]->getYPosition() + area[i][j]->getWidth(),
							0, area[i][j]->getSgns()[3]);
						area[i][j]->createSign(area[i][j]->getXPosition() - 25,
							area[i][j]->getYPosition() + 12, 90,
							area[i][j]->getSgns()[4]);
						break;
					case 180:
						area[i][j]->createSign(area[i][j]->getXPosition() + 12,
							area[i][j]->getYPosition() - 25, 180,
							area[i][j]->getSgns()[1]);
						area[i][j]->createSign(area[i][j]->getXPosition() +
							area[i][j]->getWidth(),
							area[i][j]->getYPosition() + 12, 270,
							area[i][j]->getSgns()[2]);
						area[i][j]->createSign(area[i][j]->getXPosition() - 25,
							area[i][j]->getYPosition() + 12, 90,
							area[i][j]->getSgns()[4]);
						break;
					}

				}
				// gdy skrzyzowanie jest typy "0", czyli 4-slotowe
				else {
					area[i][j]->createSign(area[i][j]->getXPosition() + 12,
						area[i][j]->getYPosition() - 25, 180,
						area[i][j]->getSgns()[1]);
					area[i][j]->createSign(area[i][j]->getXPosition() +
						area[i][j]->getWidth(), area[i][j]->getYPosition() + 12,
						270, area[i][j]->getSgns()[2]);
					area[i][j]->createSign(area[i][j]->getXPosition() + 12,
						area[i][j]->getYPosition() + area[i][j]->getWidth(), 0,
						area[i][j]->getSgns()[3]);
					area[i][j]->createSign(area[i][j]->getXPosition() - 25,
						area[i][j]->getYPosition() + 12, 90,
						area[i][j]->getSgns()[4]);
				}
			}
		}
	}

}

void Simulation::initialize1() {

	int topOfArea = this->top + 50;
	int leftOfArea = this->left + 50;
	int cellSize = 50;

	// wstawianie elementów makiety
	std::map<int, RoadElement*>area0;
	std::map<int, RoadElement*>area5;
	std::map<int, RoadElement*>area10;

	area0[0] = new Turning(leftOfArea, topOfArea, 0);
	area0[1] = new Road(leftOfArea + cellSize, topOfArea);
	area0[2] = new Road(leftOfArea + 2 * cellSize, topOfArea);
	area0[3] = new Road(leftOfArea + 3 * cellSize, topOfArea);
	area0[4] = new Road(leftOfArea + 4 * cellSize, topOfArea);
	area0[5] = new Crossing(leftOfArea + 5 * cellSize, topOfArea, 0, 1, 0,
		1, 1, 0);
	area0[6] = new Road(leftOfArea + 6 * cellSize, topOfArea);
	area0[7] = new Road(leftOfArea + 7 * cellSize, topOfArea);
	area0[8] = new Road(leftOfArea + 8 * cellSize, topOfArea);
	area0[9] = new Road(leftOfArea + 9 * cellSize, topOfArea);
	area0[10] = new Turning(leftOfArea + 10 * cellSize, topOfArea, 90);

	for (int i = 0; i < 11; i++) {
		if (!((i == 0) || (i == 5) || (i == 10))) {
			std::map<int, RoadElement*>temp;
			temp[0] = new Road(leftOfArea + 0 * cellSize,
				topOfArea + i * cellSize);
			temp[1] = new Grass(leftOfArea + 1 * cellSize,
				topOfArea + i * cellSize);
			temp[2] = new Grass(leftOfArea + 2 * cellSize,
				topOfArea + i * cellSize);
			temp[3] = new Grass(leftOfArea + 3 * cellSize,
				topOfArea + i * cellSize);
			temp[4] = new Grass(leftOfArea + 4 * cellSize,
				topOfArea + i * cellSize);
			temp[5] = new Road(leftOfArea + 5 * cellSize,
				topOfArea + i * cellSize);
			temp[6] = new Grass(leftOfArea + 6 * cellSize,
				topOfArea + i * cellSize);
			temp[7] = new Grass(leftOfArea + 7 * cellSize,
				topOfArea + i * cellSize);
			temp[8] = new Grass(leftOfArea + 8 * cellSize,
				topOfArea + i * cellSize);
			temp[9] = new Grass(leftOfArea + 9 * cellSize,
				topOfArea + i * cellSize);
			temp[10] = new Road(leftOfArea + 10 * cellSize,
				topOfArea + i * cellSize);
			area[i] = temp;
		}
	}

	area5[0] = new Crossing(leftOfArea, topOfArea + 5 * cellSize, 270, 1, 0,
		1, 1, 1);
	area5[1] = new Road(leftOfArea + cellSize, topOfArea + 5 * cellSize);
	area5[2] = new Road(leftOfArea + 2 * cellSize, topOfArea + 5 * cellSize);
	area5[3] = new Road(leftOfArea + 3 * cellSize, topOfArea + 5 * cellSize);
	area5[4] = new Road(leftOfArea + 4 * cellSize, topOfArea + 5 * cellSize);
	area5[5] = new Crossing(leftOfArea + 5 * cellSize, topOfArea + 5 * cellSize,
		0, 0, 0, 1, 1, 0);
	area5[6] = new Road(leftOfArea + 6 * cellSize, topOfArea + 5 * cellSize);
	area5[7] = new Road(leftOfArea + 7 * cellSize, topOfArea + 5 * cellSize);
	area5[8] = new Road(leftOfArea + 8 * cellSize, topOfArea + 5 * cellSize);
	area5[9] = new Road(leftOfArea + 9 * cellSize, topOfArea + 5 * cellSize);
	area5[10] = new Crossing(leftOfArea + 10 * cellSize,
		topOfArea + 5 * cellSize, 90, 1, 0, 0, 1, 1);

	area10[0] = new Turning(leftOfArea, topOfArea + 10 * cellSize, 270);
	area10[1] = new Road(leftOfArea + cellSize, topOfArea + 10 * cellSize);
	area10[2] = new Road(leftOfArea + 2 * cellSize, topOfArea + 10 * cellSize);
	area10[3] = new Road(leftOfArea + 3 * cellSize, topOfArea + 10 * cellSize);
	area10[4] = new Road(leftOfArea + 4 * cellSize, topOfArea + 10 * cellSize);
	area10[5] = new Crossing(leftOfArea + 5 * cellSize,
		topOfArea + 10 * cellSize, 180, 1, 1, 1, 0, 0);
	area10[6] = new Road(leftOfArea + 6 * cellSize, topOfArea + 10 * cellSize);
	area10[7] = new Road(leftOfArea + 7 * cellSize, topOfArea + 10 * cellSize);
	area10[8] = new Road(leftOfArea + 8 * cellSize, topOfArea + 10 * cellSize);
	area10[9] = new Road(leftOfArea + 9 * cellSize, topOfArea + 10 * cellSize);
	area10[10] = new Turning(leftOfArea + 10 * cellSize,
		topOfArea + 10 * cellSize, 180);

	this->area[0] = area0;
	this->area[5] = area5;
	this->area[10] = area10;

	// narysowanie znaków
	this->drawSigns(this->area);

	// dodawanie uczestników ruchu

	for (int i = 0; i < 5; i++) {
		this->roadParticipants[i] =
			new Car(this->left + 40 * i + 50, this->top + 25 + 50, 2, 2, 0,
			"C:\\grafika\\car3.jpg");
	}

	this->roadParticipants[5] = new PriviligedVehicle(550, 150, 3, 2, 90);
	// this->roadParticipants[1]= new Car(450, 330, 2, 1, 180);
}

void Simulation::simulate() {
	int cykl = 0;
	if (this->run == true) {
		Form1->Label46->Text = "Dzia³a";
	}
	else {
		Form1->Label46->Text = "Stop";
	}
	// if(this->run==true){

	while (this->run == true) {

		cykl++;
		Application->ProcessMessages();
		Sleep(1);
		Form1->Label1->Text = cykl;
		for (int k = 0; k < this->roadParticipants.size(); k++) {

			this->roadParticipants[k]->update(this->area, this->roadParticipants);
		}
	}

	// }

}

void Simulation::pause() {

}

bool Simulation::isRun() {

	return this->run;
}

void Simulation::setRun(bool now) {
	this->run = now;

}

void Simulation::initialize2() {

	int topOfArea = this->top + 50;
	int leftOfArea = this->left + 50;
	int cellSize = 50;

	// wstawianie elementów makiety
	std::map<int, RoadElement*>area0;
	std::map<int, RoadElement*>area4;
	std::map<int, RoadElement*>area7;
	std::map<int, RoadElement*>area10;

	area0[0] = new Turning(leftOfArea, topOfArea, 0);
	area0[1] = new Road(leftOfArea + cellSize, topOfArea);
	area0[2] = new Road(leftOfArea + 2 * cellSize, topOfArea);
	area0[3] = new Road(leftOfArea + 3 * cellSize, topOfArea);
	area0[4] = new Road(leftOfArea + 4 * cellSize, topOfArea);
	area0[5] = new Road(leftOfArea + 5 * cellSize, topOfArea);
	area0[6] = new Turning(leftOfArea + 6 * cellSize, topOfArea, 90);
	area0[7] = new Grass(leftOfArea + 7 * cellSize, topOfArea);
	area0[8] = new Grass(leftOfArea + 8 * cellSize, topOfArea);
	area0[9] = new Grass(leftOfArea + 9 * cellSize, topOfArea);
	area0[10] = new Grass(leftOfArea + 10 * cellSize, topOfArea);

	for (int i = 0; i < 11; i++) {
		if ((i == 1) || (i == 2) || (i == 3)) {
			std::map<int, RoadElement*>temp;
			temp[0] = new Road(leftOfArea + 0 * cellSize,
				topOfArea + i * cellSize);
			temp[1] = new Grass(leftOfArea + 1 * cellSize,
				topOfArea + i * cellSize);
			temp[2] = new Grass(leftOfArea + 2 * cellSize,
				topOfArea + i * cellSize);
			temp[3] = new Grass(leftOfArea + 3 * cellSize,
				topOfArea + i * cellSize);
			temp[4] = new Grass(leftOfArea + 4 * cellSize,
				topOfArea + i * cellSize);
			temp[5] = new Grass(leftOfArea + 5 * cellSize,
				topOfArea + i * cellSize);
			temp[6] = new Road(leftOfArea + 6 * cellSize,
				topOfArea + i * cellSize);
			temp[7] = new Grass(leftOfArea + 7 * cellSize,
				topOfArea + i * cellSize);
			temp[8] = new Grass(leftOfArea + 8 * cellSize,
				topOfArea + i * cellSize);
			temp[9] = new Grass(leftOfArea + 9 * cellSize,
				topOfArea + i * cellSize);
			temp[10] = new Grass(leftOfArea + 10 * cellSize,
				topOfArea + i * cellSize);
			area[i] = temp;
		}
	}

	area4[0] = new Crossing(leftOfArea, topOfArea + 4 * cellSize, 270, 1, 0,
		1, 1, 1);
	area4[1] = new Road(leftOfArea + cellSize, topOfArea + 4 * cellSize);
	area4[2] = new Road(leftOfArea + 2 * cellSize, topOfArea + 4 * cellSize);
	area4[3] = new Road(leftOfArea + 3 * cellSize, topOfArea + 4 * cellSize);
	area4[4] = new Road(leftOfArea + 4 * cellSize, topOfArea + 4 * cellSize);
	area4[5] = new Road(leftOfArea + 5 * cellSize, topOfArea + 4 * cellSize);
	area4[6] = new Crossing(leftOfArea + 6 * cellSize, topOfArea + 4 * cellSize,
		180, 1, 0, 1, 1, 0);
	area4[7] = new Road(leftOfArea + 7 * cellSize, topOfArea + 4 * cellSize);
	area4[8] = new Road(leftOfArea + 8 * cellSize, topOfArea + 4 * cellSize);
	area4[9] = new Road(leftOfArea + 9 * cellSize, topOfArea + 4 * cellSize);
	area4[10] = new Turning(leftOfArea + 10 * cellSize,
		topOfArea + 4 * cellSize, 90);

	area7[0] = new Crossing(leftOfArea, topOfArea + 7 * cellSize, 270, 1, 0,
		1, 1, 1);
	area7[1] = new Road(leftOfArea + cellSize, topOfArea + 7 * cellSize);
	area7[2] = new Road(leftOfArea + 2 * cellSize, topOfArea + 7 * cellSize);
	area7[3] = new Road(leftOfArea + 3 * cellSize, topOfArea + 7 * cellSize);
	area7[4] = new Road(leftOfArea + 4 * cellSize, topOfArea + 7 * cellSize);
	area7[5] = new Road(leftOfArea + 5 * cellSize, topOfArea + 7 * cellSize);
	area7[6] = new Road(leftOfArea + 6 * cellSize, topOfArea + 7 * cellSize);
	area7[7] = new Road(leftOfArea + 7 * cellSize, topOfArea + 7 * cellSize);
	area7[8] = new Road(leftOfArea + 8 * cellSize, topOfArea + 7 * cellSize);
	area7[9] = new Road(leftOfArea + 9 * cellSize, topOfArea + 7 * cellSize);
	area7[10] = new Crossing(leftOfArea + 10 * cellSize,
		topOfArea + 7 * cellSize, 90, 1, 0, 0, 1, 1);

	for (int i = 0; i < 11; i++) {
		if (((i == 5) || (i == 6) || (i == 8) || (i == 9))) {
			std::map<int, RoadElement*>temp;
			temp[0] = new Road(leftOfArea + 0 * cellSize,
				topOfArea + i * cellSize);
			temp[1] = new Grass(leftOfArea + 1 * cellSize,
				topOfArea + i * cellSize);
			temp[2] = new Grass(leftOfArea + 2 * cellSize,
				topOfArea + i * cellSize);
			temp[3] = new Grass(leftOfArea + 3 * cellSize,
				topOfArea + i * cellSize);
			temp[4] = new Grass(leftOfArea + 4 * cellSize,
				topOfArea + i * cellSize);
			temp[5] = new Grass(leftOfArea + 5 * cellSize,
				topOfArea + i * cellSize);
			temp[6] = new Grass(leftOfArea + 6 * cellSize,
				topOfArea + i * cellSize);
			temp[7] = new Grass(leftOfArea + 7 * cellSize,
				topOfArea + i * cellSize);
			temp[8] = new Grass(leftOfArea + 8 * cellSize,
				topOfArea + i * cellSize);
			temp[9] = new Grass(leftOfArea + 9 * cellSize,
				topOfArea + i * cellSize);
			temp[10] = new Road(leftOfArea + 10 * cellSize,
				topOfArea + i * cellSize);
			area[i] = temp;
		}
	}

	area10[0] = new Turning(leftOfArea, topOfArea + 10 * cellSize, 270);
	area10[1] = new Road(leftOfArea + cellSize, topOfArea + 10 * cellSize);
	area10[2] = new Road(leftOfArea + 2 * cellSize, topOfArea + 10 * cellSize);
	area10[3] = new Road(leftOfArea + 3 * cellSize, topOfArea + 10 * cellSize);
	area10[4] = new Road(leftOfArea + 4 * cellSize, topOfArea + 10 * cellSize);
	area10[5] = new Road(leftOfArea + 5 * cellSize, topOfArea + 10 * cellSize);
	area10[6] = new Road(leftOfArea + 6 * cellSize, topOfArea + 10 * cellSize);
	area10[7] = new Road(leftOfArea + 7 * cellSize, topOfArea + 10 * cellSize);
	area10[8] = new Road(leftOfArea + 8 * cellSize, topOfArea + 10 * cellSize);
	area10[9] = new Road(leftOfArea + 9 * cellSize, topOfArea + 10 * cellSize);
	area10[10] = new Turning(leftOfArea + 10 * cellSize,
		topOfArea + 10 * cellSize, 180);

	this->area[0] = area0;
	this->area[4] = area4;
	this->area[7] = area7;
	this->area[10] = area10;

	this->drawSigns(this->area);

	//
	// for(int i=0 ; i<3;i++){
	// this->roadParticipants[i]= new Car(this->left+40*i+50, this->top+25+50, 2, 2, 0);
	// }
	//
	// this->roadParticipants[3]= new PriviligedVehicle(375, 150, 1, 2, 90);

	// Car::Car(int xPosition, int yPosition, int direction, int targetVelocity, int orientation){
	this->roadParticipants[0] = new Car(this->left + 130, this->top + 25 + 550,
		2, 1, 0, "C:\\grafika\\car3.jpg");
	this->roadParticipants[1] = new Car(this->left + 250, this->top + 25 + 550,
		2, 1, 0, "C:\\grafika\\car4.jpg");
	this->roadParticipants[2] = new Car(this->left + 130, this->top + 25 + 50,
		2, 2, 0, "C:\\grafika\\car2.jpg");
	this->roadParticipants[3] = new Car(this->left + 170, this->top + 25 + 50,
		2, 2, 0, "C:\\grafika\\car2.jpg");
	this->roadParticipants[4] = new PriviligedVehicle(375, 150, 1, 2, 90);
	// this->roadParticipants[5]= new PriviligedVehicle(375, 200, 1, 2, 90);

}

void Simulation::initialize3() {
	int topOfArea = this->top + 50;
	int leftOfArea = this->left + 50;
	int cellSize = 50;

	std::map<int, RoadElement*>area0;
	std::map<int, RoadElement*>area1;
	std::map<int, RoadElement*>area2;
	std::map<int, RoadElement*>area3;
	std::map<int, RoadElement*>area4;
	std::map<int, RoadElement*>area5;
	std::map<int, RoadElement*>area6;
	std::map<int, RoadElement*>area7;
	std::map<int, RoadElement*>area8;
	std::map<int, RoadElement*>area9;
	std::map<int, RoadElement*>area10;

	area0[0] = new Turning(leftOfArea + 0 * cellSize,
		topOfArea + 0 * cellSize, 0);
	area0[1] = new Road(leftOfArea + cellSize, topOfArea + 0 * cellSize);
	area0[2] = new Road(leftOfArea + 2 * cellSize, topOfArea + 0 * cellSize);
	area0[3] = new Road(leftOfArea + 3 * cellSize, topOfArea + 0 * cellSize);
	area0[4] = new Road(leftOfArea + 4 * cellSize, topOfArea + 0 * cellSize);
	area0[5] = new Road(leftOfArea + 5 * cellSize, topOfArea + 0 * cellSize);
	area0[6] = new Road(leftOfArea + 6 * cellSize, topOfArea + 0 * cellSize);
	area0[7] = new Road(leftOfArea + 7 * cellSize, topOfArea + 0 * cellSize);
	area0[8] = new Road(leftOfArea + 8 * cellSize, topOfArea + 0 * cellSize);
	area0[9] = new Turning(leftOfArea + 9 * cellSize,
		topOfArea + 0 * cellSize, 90);
	area0[10] = new Grass(leftOfArea + 10 * cellSize, topOfArea + 0 * cellSize);

	area1[0] = new Road(leftOfArea + 0 * cellSize, topOfArea + 1 * cellSize);
	area1[1] = new Grass(leftOfArea + 1 * cellSize, topOfArea + 1 * cellSize);
	area1[2] = new Grass(leftOfArea + 2 * cellSize, topOfArea + 1 * cellSize);
	area1[3] = new Grass(leftOfArea + 3 * cellSize, topOfArea + 1 * cellSize);
	area1[4] = new Grass(leftOfArea + 4 * cellSize, topOfArea + 1 * cellSize);
	area1[5] = new Grass(leftOfArea + 5 * cellSize, topOfArea + 1 * cellSize);
	area1[6] = new Grass(leftOfArea + 6 * cellSize, topOfArea + 1 * cellSize);
	area1[7] = new Grass(leftOfArea + 7 * cellSize, topOfArea + 1 * cellSize);
	area1[8] = new Grass(leftOfArea + 8 * cellSize, topOfArea + 1 * cellSize);
	area1[9] = new Road(leftOfArea + 9 * cellSize, topOfArea + 1 * cellSize);
	area1[10] = new Grass(leftOfArea + 10 * cellSize, topOfArea + 1 * cellSize);

	area2[0] = new Road(leftOfArea + 0 * cellSize, topOfArea + 2 * cellSize);
	area2[1] = new Grass(leftOfArea + 1 * cellSize, topOfArea + 2 * cellSize);
	area2[2] = new Grass(leftOfArea + 2 * cellSize, topOfArea + 2 * cellSize);
	area2[3] = new Grass(leftOfArea + 3 * cellSize, topOfArea + 2 * cellSize);
	area2[4] = new Turning(leftOfArea + 4 * cellSize,
		topOfArea + 2 * cellSize, 0);
	area2[5] = new Road(leftOfArea + 5 * cellSize, topOfArea + 2 * cellSize);
	area2[6] = new Road(leftOfArea + 6 * cellSize, topOfArea + 2 * cellSize);
	area2[7] = new Road(leftOfArea + 7 * cellSize, topOfArea + 2 * cellSize);
	area2[8] = new Road(leftOfArea + 8 * cellSize, topOfArea + 2 * cellSize);
	area2[9] = new Turning(leftOfArea + 9 * cellSize,
		topOfArea + 2 * cellSize, 180);
	area2[10] = new Grass(leftOfArea + 10 * cellSize, topOfArea + 2 * cellSize);

	area3[0] = new Road(leftOfArea + 0 * cellSize, topOfArea + 3 * cellSize);
	area3[1] = new Grass(leftOfArea + 1 * cellSize, topOfArea + 3 * cellSize);
	area3[2] = new Grass(leftOfArea + 2 * cellSize, topOfArea + 3 * cellSize);
	area3[3] = new Grass(leftOfArea + 3 * cellSize, topOfArea + 3 * cellSize);
	area3[4] = new Road(leftOfArea + 4 * cellSize, topOfArea + 3 * cellSize);
	area3[5] = new Grass(leftOfArea + 5 * cellSize, topOfArea + 3 * cellSize);
	area3[6] = new Grass(leftOfArea + 6 * cellSize, topOfArea + 3 * cellSize);
	area3[7] = new Grass(leftOfArea + 7 * cellSize, topOfArea + 3 * cellSize);
	area3[8] = new Grass(leftOfArea + 8 * cellSize, topOfArea + 3 * cellSize);
	area3[9] = new Grass(leftOfArea + 9 * cellSize, topOfArea + 3 * cellSize);
	area3[10] = new Grass(leftOfArea + 10 * cellSize, topOfArea + 3 * cellSize);

	area4[0] = new Turning(leftOfArea + 0 * cellSize,
		topOfArea + 4 * cellSize, 270);
	area4[1] = new Road(leftOfArea + 1 * cellSize, topOfArea + 4 * cellSize);
	area4[2] = new Road(leftOfArea + 2 * cellSize, topOfArea + 4 * cellSize);
	area4[3] = new Road(leftOfArea + 3 * cellSize, topOfArea + 4 * cellSize);
	area4[4] = new Crossing(leftOfArea + 4 * cellSize, topOfArea + 4 * cellSize,
		0, 0, 1, 0, 1, 0);
	area4[5] = new Road(leftOfArea + 5 * cellSize, topOfArea + 4 * cellSize);
	area4[6] = new Turning(leftOfArea + 6 * cellSize,
		topOfArea + 4 * cellSize, 90);
	area4[7] = new Grass(leftOfArea + 7 * cellSize, topOfArea + 4 * cellSize);
	area4[8] = new Grass(leftOfArea + 8 * cellSize, topOfArea + 4 * cellSize);
	area4[9] = new Grass(leftOfArea + 9 * cellSize, topOfArea + 4 * cellSize);
	area4[10] = new Grass(leftOfArea + 10 * cellSize, topOfArea + 4 * cellSize);

	area5[0] = new Grass(leftOfArea + 0 * cellSize, topOfArea + 5 * cellSize);
	area5[1] = new Grass(leftOfArea + 1 * cellSize, topOfArea + 5 * cellSize);
	area5[2] = new Grass(leftOfArea + 2 * cellSize, topOfArea + 5 * cellSize);
	area5[3] = new Grass(leftOfArea + 3 * cellSize, topOfArea + 5 * cellSize);
	area5[4] = new Road(leftOfArea + 4 * cellSize, topOfArea + 5 * cellSize);
	area5[5] = new Grass(leftOfArea + 5 * cellSize, topOfArea + 5 * cellSize);
	area5[6] = new Turning(leftOfArea + 6 * cellSize,
		topOfArea + 5 * cellSize, 270);
	area5[7] = new Road(leftOfArea + 7 * cellSize, topOfArea + 5 * cellSize);
	area5[8] = new Road(leftOfArea + 8 * cellSize, topOfArea + 5 * cellSize);
	area5[9] = new Road(leftOfArea + 9 * cellSize, topOfArea + 5 * cellSize);
	area5[10] = new Turning(leftOfArea + 10 * cellSize,
		topOfArea + 5 * cellSize, 90);

	area6[0] = new Turning(leftOfArea + 0 * cellSize,
		topOfArea + 6 * cellSize, 0);
	area6[1] = new Road(leftOfArea + 1 * cellSize, topOfArea + 6 * cellSize);
	area6[2] = new Road(leftOfArea + 2 * cellSize, topOfArea + 6 * cellSize);
	area6[3] = new Road(leftOfArea + 3 * cellSize, topOfArea + 6 * cellSize);
	area6[4] = new Turning(leftOfArea + 4 * cellSize,
		topOfArea + 6 * cellSize, 180);
	area6[5] = new Grass(leftOfArea + 5 * cellSize, topOfArea + 6 * cellSize);
	area6[6] = new Grass(leftOfArea + 6 * cellSize, topOfArea + 6 * cellSize);
	area6[7] = new Grass(leftOfArea + 7 * cellSize, topOfArea + 6 * cellSize);
	area6[8] = new Grass(leftOfArea + 8 * cellSize, topOfArea + 6 * cellSize);
	area6[9] = new Grass(leftOfArea + 9 * cellSize, topOfArea + 6 * cellSize);
	area6[10] = new Road(leftOfArea + 10 * cellSize, topOfArea + 6 * cellSize);

	area7[0] = new Road(leftOfArea + 0 * cellSize, topOfArea + 7 * cellSize);
	area7[1] = new Grass(leftOfArea + 1 * cellSize, topOfArea + 7 * cellSize);
	area7[2] = new Grass(leftOfArea + 2 * cellSize, topOfArea + 7 * cellSize);
	area7[3] = new Grass(leftOfArea + 3 * cellSize, topOfArea + 7 * cellSize);
	area7[4] = new Grass(leftOfArea + 4 * cellSize, topOfArea + 7 * cellSize);
	area7[5] = new Grass(leftOfArea + 5 * cellSize, topOfArea + 7 * cellSize);
	area7[6] = new Turning(leftOfArea + 6 * cellSize,
		topOfArea + 7 * cellSize, 0);
	area7[7] = new Road(leftOfArea + 7 * cellSize, topOfArea + 7 * cellSize);
	area7[8] = new Turning(leftOfArea + 8 * cellSize,
		topOfArea + 7 * cellSize, 90);
	area7[9] = new Grass(leftOfArea + 9 * cellSize, topOfArea + 7 * cellSize);
	area7[10] = new Road(leftOfArea + 10 * cellSize, topOfArea + 7 * cellSize);

	area8[0] = new Road(leftOfArea + 0 * cellSize, topOfArea + 8 * cellSize);
	area8[1] = new Grass(leftOfArea + 1 * cellSize, topOfArea + 8 * cellSize);
	area8[2] = new Grass(leftOfArea + 2 * cellSize, topOfArea + 8 * cellSize);
	area8[3] = new Grass(leftOfArea + 3 * cellSize, topOfArea + 8 * cellSize);
	area8[4] = new Grass(leftOfArea + 4 * cellSize, topOfArea + 8 * cellSize);
	area8[5] = new Grass(leftOfArea + 5 * cellSize, topOfArea + 8 * cellSize);
	area8[6] = new Road(leftOfArea + 6 * cellSize, topOfArea + 8 * cellSize);
	area8[7] = new Grass(leftOfArea + 7 * cellSize, topOfArea + 8 * cellSize);
	area8[8] = new Road(leftOfArea + 8 * cellSize, topOfArea + 8 * cellSize);
	area8[9] = new Grass(leftOfArea + 9 * cellSize, topOfArea + 8 * cellSize);
	area8[10] = new Road(leftOfArea + 10 * cellSize, topOfArea + 8 * cellSize);

	area9[0] = new Road(leftOfArea + 0 * cellSize, topOfArea + 9 * cellSize);
	area9[1] = new Grass(leftOfArea + 1 * cellSize, topOfArea + 9 * cellSize);
	area9[2] = new Grass(leftOfArea + 2 * cellSize, topOfArea + 9 * cellSize);
	area9[3] = new Grass(leftOfArea + 3 * cellSize, topOfArea + 9 * cellSize);
	area9[4] = new Grass(leftOfArea + 4 * cellSize, topOfArea + 9 * cellSize);
	area9[5] = new Grass(leftOfArea + 5 * cellSize, topOfArea + 9 * cellSize);
	area9[6] = new Road(leftOfArea + 6 * cellSize, topOfArea + 9 * cellSize);
	area9[7] = new Grass(leftOfArea + 7 * cellSize, topOfArea + 9 * cellSize);
	area9[8] = new Road(leftOfArea + 8 * cellSize, topOfArea + 9 * cellSize);
	area9[9] = new Grass(leftOfArea + 9 * cellSize, topOfArea + 9 * cellSize);
	area9[10] = new Road(leftOfArea + 10 * cellSize, topOfArea + 9 * cellSize);

	area10[0] = new Turning(leftOfArea + 0 * cellSize,
		topOfArea + 10 * cellSize, 270);
	area10[1] = new Road(leftOfArea + 1 * cellSize, topOfArea + 10 * cellSize);
	area10[2] = new Road(leftOfArea + 2 * cellSize, topOfArea + 10 * cellSize);
	area10[3] = new Road(leftOfArea + 3 * cellSize, topOfArea + 10 * cellSize);
	area10[4] = new Road(leftOfArea + 4 * cellSize, topOfArea + 10 * cellSize);
	area10[5] = new Road(leftOfArea + 5 * cellSize, topOfArea + 10 * cellSize);
	area10[6] = new Turning(leftOfArea + 6 * cellSize,
		topOfArea + 10 * cellSize, 180);
	area10[7] = new Grass(leftOfArea + 7 * cellSize, topOfArea + 10 * cellSize);
	area10[8] = new Turning(leftOfArea + 8 * cellSize,
		topOfArea + 10 * cellSize, 270);
	area10[9] = new Road(leftOfArea + 9 * cellSize, topOfArea + 10 * cellSize);
	area10[10] = new Turning(leftOfArea + 10 * cellSize,
		topOfArea + 10 * cellSize, 180);

	this->area[0] = area0;
	this->area[1] = area1;
	this->area[2] = area2;
	this->area[3] = area3;
	this->area[4] = area4;
	this->area[5] = area5;
	this->area[6] = area6;
	this->area[7] = area7;
	this->area[8] = area8;
	this->area[9] = area9;
	this->area[10] = area10;

	this->drawSigns(this->area);

	for (int i = 0; i < 3; i++) {
		this->roadParticipants[i] =
			new Car(this->left + 50 * i + 50, this->top + 25 + 50, 2, 2, 0,
			"C:\\grafika\\car3.jpg");
	}

	this->roadParticipants[3] = new PriviligedVehicle(350, 150, 4, 2, 0);

}

void Simulation::end() {
	// for(int i=0 ; i<this->area.size() ; i++){
	// for(int j=0 ; j<this->area[i].size() ; j++){
	// delete this->area[i][j];
	// }}
	//
	// for(int i=0 ; i<this->roadParticipants.size() ; i++){
	// delete roadParticipants[i];
	// }

	for (int i = 0; i < this->area.size(); i++) {
		this->area[i].clear();
	}
	this->area.clear();
	this->roadParticipants.clear();

}

Simulation::~Simulation() {
}

int Simulation::getAreaSize() {
	return this->area.size();
}
