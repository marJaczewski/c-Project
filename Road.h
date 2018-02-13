// ---------------------------------------------------------------------------

#ifndef RoadH
#define RoadH

#include "Simulation.h"
#include "RoadElement.h"

// ---------------------------------------------------------------------------
class Road : public RoadElement {

public:
	///Constructor of road
	Road(int xPosition, int yPosition);

	///Destructor
	~Road();

};
#endif
