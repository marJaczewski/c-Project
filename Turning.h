// ---------------------------------------------------------------------------

#ifndef TurningH
#define TurningH

#include "RoadElement.h"

// ---------------------------------------------------------------------------
class Turning : public RoadElement {

public:
	///Constructor of Turning
	Turning(int xPosition, int yPosition, int orientation);

	///Destructor
	~Turning();

};

#endif
