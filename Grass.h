// ---------------------------------------------------------------------------

#ifndef GrassH
#define GrassH

#include "RoadElement.h"

// ---------------------------------------------------------------------------
class Grass : public RoadElement {

public:
	///Constructor of grass
	Grass(int xPosition, int yPosition);

	///Destructor
	~Grass();

};

#endif
