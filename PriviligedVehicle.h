// ---------------------------------------------------------------------------

#ifndef PriviligedVehicleH
#define PriviligedVehicleH
#include "RoadParticipant.h"

// ---------------------------------------------------------------------------

class PriviligedVehicle : public RoadParticipant {
public:
	///That is a constructor of the PriviligedVehicle class
	PriviligedVehicle(int xPosition, int yPosition, int direction,
		int targetVelocity, int orientation);
	/** That is the most important method. Its contains references to
	 * other basic methods.
	 * It is directly calling in the main loop of program. */
	void update(std::map<int, std::map<int, RoadElement*> >area,
		std::map<int, RoadParticipant *>roadParticipants);
	///That is a destructor of the PriviligedVehicle class
	~PriviligedVehicle();
	/** Here is taken decision if "this" participant can cross the crossing.
	 *  If true participant can move, otherwise - no.
	 *  Return value is depend on the sign on the specific slot of on
	 *  crossing */
	bool crossingManager(RoadElement * roadElement);

};

#endif
