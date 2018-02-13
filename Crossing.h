// ---------------------------------------------------------------------------

#ifndef CrossingH
#define CrossingH

#include "RoadElement.h"
#include "RoadParticipant.h"
#include<map>

// ---------------------------------------------------------------------------
class Crossing : public RoadElement {

public:
	///Crossing constructor
	Crossing(int xPosition, int yPosition, int orientation, int type, int sgn1,
		int sgn2, int sgn3, int sgn4);
	///Crossing type getter
	int getType();
	///Destructor
	~Crossing();

};
#endif
