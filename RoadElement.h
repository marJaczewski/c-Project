// ---------------------------------------------------------------------------

#ifndef RoadElementH
#define RoadElementH
#include<map>
#include "RoadParticipant.h"
#include "Element.h"
// #include "EmptyCar.h"
// ---------------------------------------------------------------------------
class RoadParticipant;
class EmptyCar;

class RoadElement : public Element {

protected:
	int type;
	int sgns[5];
	int slots[5];
	RoadParticipant *vehicleSlots[5];

public:
	///type Setter
	int getType();
	///destructor
	virtual ~RoadElement();
	///Method creating signs connected with specyfic roadElement
	void createSign(int xPosition, int yPosition, int orientation, int sgn);
	/** slots Setter, slot(e.g. crossing slot) is data
	 * concerning if there is there a vehicle near this element in specyfic position */
	void setSlots(std::map<int, RoadParticipant *>rP);
	///Method setting vehicles associated with specyfic roadElement
	void setVehicleSlots(std::map<int, RoadParticipant *>rP);
	///Vector of singns related wirh specyfic roadElement getter
	int * getSgns();
	///roadElement slot getter
	void setSingleSlot(int slotNumber, int value);
	///slots getter
	int * getSlots();
	///vehicleSlots getter
	RoadParticipant ** getVehicles();

};

#endif
