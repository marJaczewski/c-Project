// ---------------------------------------------------------------------------

#ifndef RoadParticipantH
#define RoadParticipantH

#include <map>
#include "RoadElement.h"
#include "Element.h"

// ---------------------------------------------------------------------------
class RoadElement;

class RoadParticipant : public Element {

protected:
	int rate;
	int targetVelocity;
	int direction;

	int newDirection;
	int startedCrossing;
	bool choosenDirection;
	bool onCrossing;

public:

	///Method moving object in its actual direction
	void move();
	///Method responsible for driving on turnings
	void turn(RoadElement * roadElement);
	///Method implementing the vehicles behavior on crossings
	void cross(RoadElement * roadElement);
	///Checking the type of roadElement vehicle is on
	bool checkArea(RoadElement * element);
	///The rotation angle setter
	void setOrientation(int orientation);
	///Choosing the driving direction / newDirection setter
	void randomDirection(RoadElement * roadElement);
	///ChoosenDirection setter choosen direction is a flag, if new direction was choosen
	void setChoosenDirection(bool choosenDirection);
	///Setting coordinates of vehicle
	void go(int xPosition, int yPosition);
	///Direction setter
	int getDirection();
	/** Method checking the possible colissions with other vehicle
	 * if there is the possibility of crasch - the rate of participant is decrement */
	void checkColission(std::map<int, RoadParticipant*>roadParticipants);
	///Destructor
	virtual ~RoadParticipant();
	///Method responsible for deciding if the vehicle can cross the crossing
	virtual bool crossingManager(RoadElement * roadElement) = 0;
	///startedCrossing getter
	int getStartedCrossing();
	///startedCrossing getter
	void setStartedCrossing(int startedCrossing);
	/** That is the most important method. It contains references to
	 * other basic methods.
	 * It is directly calling in the main loop of program. */
	virtual void update(std::map<int, std::map<int, RoadElement*> >area,
		std::map<int, RoadParticipant *>roadParticipants) = 0;
	///onCrossing getter
	bool isOnCrossing();

};

#endif
