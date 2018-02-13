// ---------------------------------------------------------------------------

#pragma hdrstop
#include <sstream>
#include <string>
#include <iostream>
#include "RoadParticipant.h"
#include "Car.h"
#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

bool RoadParticipant::checkArea(RoadElement * element) {
	int up = this->yPosition;
	int down = this->yPosition +this->height;
	int left = this->xPosition;
	int right = this->xPosition +this->width;

	int elUp = element->getYPosition();
	int elDown = element->getYPosition() + element->getHeight();
	int elLeft = element->getXPosition();
	int elRight = element->getXPosition() + element->getWidth();

	if (this->direction == 4 || this->direction == 1) {

		if ((up >= elUp) && (up <= elDown) && (left >= elLeft) && (left <=
			elRight)) {

			return true;
		}
		else {

			return false;

		}
	}
	else if (this->direction == 2) {

		if ((up >= elUp) && (up <= elDown) && (right <= elRight) && (right >=
			elLeft)) {
			return true;
		}
		else {

			return false;

		}

	}
	else if (this->direction == 3) {

		if ((down >= elUp) && (down <= elDown) && (right <= elRight) &&
			(right >= elLeft)) {
			return true;
		}
		else {

			return false;

		}

	}
	else {
		return false;
	}

}

void RoadParticipant::setOrientation(int orientation) {
	this->orientation = orientation;
	this->image->RotationAngle = orientation;
}

void RoadParticipant::randomDirection(RoadElement * roadElement) {
	Randomize();
	int randDir = 99;

	switch (roadElement->getType()) {

	case 1:
		randDir = Random(2) + 1;
		Form1->Label2->Text = randDir;

		if (this->direction == 1) {
			if (roadElement->getOrientation() == 0) {
				if (randDir == 1) {
					this->newDirection = 4;
					break;
				}
				else {
					this->newDirection = 2;
					break;
				}
			}

			else if (roadElement->getOrientation() == 90) {
				if (randDir == 1) {
					this->newDirection = 4;
					break;
				}
				else {
					this->newDirection = this->direction;
					break;
				}
			}

			else if (roadElement->getOrientation() == 270) {
				if (randDir == 1) {
					this->newDirection = 2;
					break;
				}
				else {
					this->newDirection = this->direction;
					break;
				}
			}

		}

		else if (this->direction == 2) {

			if (roadElement->getOrientation() == 0) {
				if (randDir == 1) {
					this->newDirection = 3;
					break;
				}
				else {
					this->newDirection = this->direction;
					break;
				}
			}

			else if (roadElement->getOrientation() == 90) {
				if (randDir == 1) {
					this->newDirection = 1;
					break;
				}
				else {
					this->newDirection = 3;
					break;
				}
			}

			else if (roadElement->getOrientation() == 180) {
				if (randDir == 1) {
					this->newDirection = 1;
					break;
				}
				else {
					this->newDirection = this->direction;
					break;
				}
			}

		}

		else if (this->direction == 3) {

			if (roadElement->getOrientation() == 90) {
				if (randDir == 1) {
					this->newDirection = 4;
					break;
				}
				else {
					this->newDirection = this->direction;
					break;
				}
			}

			else if (roadElement->getOrientation() == 180) {
				if (randDir == 1) {
					this->newDirection = 4;
					break;
				}
				else {
					this->newDirection = 2;
					break;
				}
			}

			else if (roadElement->getOrientation() == 270) {
				if (randDir == 1) {
					this->newDirection = 2;
					break;
				}
				else {
					this->newDirection = this->direction;
					break;
				}
			}

		}

		else if (this->direction == 4) {

			if (roadElement->getOrientation() == 0) {
				if (randDir == 1) {
					this->newDirection = 3;
					break;
				}
				else {
					this->newDirection = this->direction;
					break;
				}
			}

			else if (roadElement->getOrientation() == 180) {
				if (randDir == 1) {
					this->newDirection = 1;
					break;
				}
				else {
					this->newDirection = this->direction;
					break;
				}
			}

			else if (roadElement->getOrientation() == 270) {
				if (randDir == 1) {
					this->newDirection = 1;
					break;
				}
				else {
					this->newDirection = 3;
					break;
				}
			}

		}

		break;
	case 0:

		if (this->direction == 1) {
			do {
				randDir = Random(4) + 1;
			}
			while (randDir == 3);
			this->newDirection = randDir;
		}
		if (this->direction == 2) {
			do {
				randDir = Random(4) + 1;
			}
			while (randDir == 4);
			this->newDirection = randDir;
		}
		if (this->direction == 3) {
			do {
				randDir = Random(4) + 1;
			}
			while (randDir == 1);
			this->newDirection = randDir;
		}
		if (this->direction == 4) {
			do {
				randDir = Random(4) + 1;
			}
			while (randDir == 2);
			this->newDirection = randDir;
		}

		break;
	}

	this->choosenDirection = true;

}

void RoadParticipant::setChoosenDirection(bool choosenDirection) {
	this->choosenDirection = choosenDirection;
}

void RoadParticipant::go(int xPosition, int yPosition) {
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->image->Position->X = this->xPosition;
	this->image->Position->Y = this->yPosition;
}

void RoadParticipant::checkColission
	(std::map<int, RoadParticipant*>roadParticipants) {

	int dilatation = 10;
	int min = 1000;
	int tempDistance = 10000;
	// int tempDistance;
	for (int i = 0; i < roadParticipants.size(); i++) {

		if ((roadParticipants[i]->xPosition == this->xPosition) &&
			(roadParticipants[i]->yPosition == this->yPosition)) {
			continue;
		}
		// if(this==roadParticipants[i]) {continue;}
		//

		if (this->direction == 1) {
			if (abs(this->xPosition - roadParticipants[i]->xPosition) <
				dilatation) {
				tempDistance = this->yPosition -
					roadParticipants[i]->yPosition -
					roadParticipants[i]->getHeight();
			}
		}
		else if (this->direction == 2) {
			if (abs(this->yPosition - roadParticipants[i]->yPosition) <
				dilatation) {
				tempDistance = roadParticipants[i]->xPosition -this->getWidth()
					-this->xPosition;
			}
		}
		else if (this->direction == 3) {
			if (abs(this->xPosition - roadParticipants[i]->xPosition) <
				dilatation) {
				tempDistance = roadParticipants[i]->yPosition -
					roadParticipants[i]->getWidth()-this->yPosition;
			}
		}
		else if (this->direction == 4) {
			if (abs(this->yPosition - roadParticipants[i]->yPosition) <
				dilatation) {
				tempDistance = this->xPosition -
					roadParticipants[i]->xPosition -
					roadParticipants[i]->getWidth();
			}
		}

		if (tempDistance < min) {
			min = tempDistance;
		}

		Form1->Label45->Text = tempDistance;
		Form1->Label44->Text = min;
	}
	if (min > 0) {

		if (min < 32) {
			this->rate = 1;
		}
		else if (min < 60 && min > 20) {
			this->rate = 1;
		}
		else if (min > 60) {
			this->rate = this->targetVelocity;
		}

		// if(min<100&&min>60){ this->rate=2; }
		// else	if (min<60&&min>40){ this->rate=1; }
		// else if (min<40) {    this->rate=0;}
		//
		// else if(min>100){
		// this->rate=this->targetVelocity;
		// }

		Form1->Label7->Text = roadParticipants[0]->rate;
		Form1->Label40->Text = roadParticipants[1]->rate;
		Form1->Label41->Text = roadParticipants[2]->rate;
		Form1->Label42->Text = roadParticipants[3]->rate;

		// Form1->Label42->Text= this->yPosition;

	}
}

RoadParticipant::~RoadParticipant() {
}

void RoadParticipant::move() {

	// this->checkColission(roadParticipants);

	switch (this->direction) {
	case 1:
		this->yPosition -= this->rate;
		break;

	case 2:
		this->xPosition += this->rate;
		break;

	case 3:
		this->yPosition += this->rate;
		break;
		// default:
	case 4:
		this->xPosition -= this->rate;
		break;

	}
	this->image->Position->X = this->xPosition;
	this->image->Position->Y = this->yPosition;

}

void RoadParticipant::turn(RoadElement * roadElement) {

	switch (roadElement->getOrientation()) {
	case 0:

		if (this->direction == 4) {

			if (this->xPosition -this->rate > roadElement->getXPosition()) {
				this->move();
				break;
			}
			else {
				this->setOrientation(270);
				this->direction = 3;
				this->go(roadElement->getXPosition(),
					roadElement->getYPosition());
				break;
			}
		}

		else if (this->direction == 3) {
			this->move();
			break;
		}

		else if (this->direction == 1) { // drugi przypadek pó¿niej
			if (this->yPosition > roadElement->getYPosition() +
				roadElement->getHeight() * 0.5) {
				this->move();
				break;
			}
			else {
				this->setOrientation(0);
				this->direction = 2;
				this->go(roadElement->getXPosition() + 0.5*roadElement->getWidth
					(), roadElement->getYPosition() + roadElement->getHeight()
					-this->height - 3);
				/////////////////////////////////////////
				break;
			}
		}
		else if (this->direction == 2) {
			this->move();
			break;
		}

	case 270:
		if (this->direction == 3) {
			if (this->yPosition +this->width -this->rate <
				roadElement->getYPosition() + roadElement->getHeight()) {
				this->move();
				break;
			}
			else {
				this->setOrientation(180);
				this->direction = 2;
				break;
			}
		}

		else if (this->direction == 2) {
			this->move();
			break;
		}
		else if (this->direction == 4) { // -this->width

			if (this->xPosition >= roadElement->getXPosition() +
				roadElement->getWidth() * 0.5) {

				this->move();
				break;
			}
			else {
				this->setOrientation(270);
				this->direction = 1;
				break;
			}

		}
		else if (this->direction == 1) {
			this->move();
		}
		break;

	case 180:
		if (this->direction == 2) {
			if (this->xPosition +this->width +this->rate <
				roadElement->getXPosition() + roadElement->getWidth()) {
				this->move();
				break;
			}
			else {
				this->setOrientation(90);
				this->direction = 1;
				break;
			}
		}
		else if (this->direction == 1) {
			this->move();
			break;
		}
		else if (this->direction == 3) {
			if (this->yPosition +this->height < roadElement->getYPosition() +
				roadElement->getHeight() * 0.5) {
				this->move();
				break;
			}
			else {
				this->setOrientation(180);
				this->direction = 4;
				break;
			}

		}

	case 90:
		if (this->direction == 1) {

			if (this->yPosition -this->height +this->rate >
				roadElement->getYPosition()) {
				this->move();
				break;
			}
			else {
				this->setOrientation(0);
				this->direction = 4;
				this->go(roadElement->getXPosition(),
					roadElement->getYPosition() + 1);
				break;
			}
		}
		else if (this->direction == 4) {
			this->move();
			break;
		}

		else if (this->direction == 2) {
			if (this->xPosition +this->width < roadElement->getXPosition() +
				roadElement->getWidth() * 0.5) {
				this->move();
				break;
			}
			else {
				this->setOrientation(90);
				this->direction = 3;
				break;
			}
		}
		else if (this->direction == 3) {
			this->move();
			break;
		}

	}

}

void RoadParticipant::cross(RoadElement * roadElement) {

	switch (this->direction) {

	case 1:
		if (this->newDirection == 4) {
			if (this->yPosition -this->height +this->rate >
				roadElement->getYPosition()) {
				this->move();
				break;
			}
			else {
				this->setOrientation(0);
				this->direction = 4;
				this->go(roadElement->getXPosition(),
					roadElement->getYPosition() + 2);
				///////////////////
				break;
			}

		}
		if (this->newDirection == 2) {
			if (this->yPosition > roadElement->getYPosition() +
				roadElement->getHeight() * 0.5) {
				this->move();
				break;
			}
			else {
				this->setOrientation(0);
				this->direction = 2;
				break;
			}
		}
		if (this->newDirection == 1) {
			this->move();
			break;
		}

	case 2:
		if (this->newDirection == 3) {

			if (this->xPosition +this->width < roadElement->getXPosition() +
				roadElement->getWidth() * 0.5) {
				this->move();
				break;
			}
			else {
				this->setOrientation(90);
				this->direction = 3;
				break;
			}

		}
		if (this->newDirection == 1) {
			if (this->xPosition +this->width +this->rate <
				roadElement->getXPosition() + roadElement->getWidth()) {
				this->move();
				break;
			}
			else {
				this->setOrientation(90);
				this->direction = 1;
				break;
			}
		}
		if (this->newDirection == 2) {
			this->move();
			break;
		}

		//
	case 3:
		if (this->newDirection == 2) { // width //-
			if (this->yPosition +this->height +this->rate <
				roadElement->getYPosition() + roadElement->getHeight()) {
				this->move();
				break;
			}
			else {
				this->setOrientation(180);
				this->direction = 2;
				break;
			}

		}
		if (this->newDirection == 4) {
			if (this->yPosition +this->height < roadElement->getYPosition() +
				roadElement->getHeight() * 0.5) {
				this->move();
				break;
			}
			else {
				this->setOrientation(180);
				this->direction = 4;
				break;
			}

		}
		if (this->newDirection == 3) {
			this->move();
			break;
		}

	case 4:
		if (this->newDirection == 1) {
			if (this->xPosition >= roadElement->getXPosition() +
				roadElement->getWidth() * 0.5) {

				this->move();
				break;
			}
			else {
				this->setOrientation(270);
				this->direction = 1;
				break;
			}
		}
		if (this->newDirection == 3) {
			if (this->xPosition -this->rate > roadElement->getXPosition()) {
				this->move();
				break;
			}
			else {
				this->setOrientation(270);
				this->direction = 3;
				break;
			}
		}
		if (this->newDirection == 4) {
			this->move();
			break;
		}

	}
}

int RoadParticipant::getDirection() {
	return this->direction;

}

int RoadParticipant::getStartedCrossing() {
	return this->startedCrossing;
}

void RoadParticipant::setStartedCrossing(int startedCrossingw) {
	this->startedCrossing = startedCrossingw;

}

bool RoadParticipant::isOnCrossing() {
	return this->onCrossing;
}
