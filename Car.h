// ---------------------------------------------------------------------------

#ifndef CarH
#define CarH
#include "RoadParticipant.h"

// ---------------------------------------------------------------------------

class RoadElement;
class RoadParticipant;
class PriviligedVehicle;

class Car : public RoadParticipant {
public:

	///That is a constructor of the Car class
	Car(int xPosition, int yPosition, int direction, int targetVelocity,
		int orientation, String path);
	///That is a destructor of the Car class
	~Car();
	/** That is the most important method. Its contains references to
	 * other basic methods.
	 * It is directly calling in the main loop of program. */
	void update(std::map<int, std::map<int, RoadElement*> >area,
		std::map<int, RoadParticipant *>roadParticipants);
	/** Here is taken decision if "this" participant can cross the crossing.
	 *  If true participant can move, otherwise - no.
	 *  Return value is depend on the sign on the specific slot of on
	 *  crossing and if there are any vehicles with priority */
	bool crossingManager(RoadElement * roadElement);

};

#endif
