// ---------------------------------------------------------------------------

#ifndef SimulationH
#define SimulationH
#include <map>
#include<iostream>

#include "Unit1.h"


#include "RoadElement.h"
#include "RoadParticipant.h"


// ---------------------------------------------------------------------------

/// doxygen
class Simulation {
private:

	int top;
	int left;
	bool run;

	std::map<int, std::map<int, RoadElement*> >area;
	std::map<int, RoadParticipant*>roadParticipants;

public:
	///Map size getter
	int getAreaSize();
	///Constructor of The Simulation
	// Simulation(int top, int left, std::map <int, std::map <int, RoadElement* > > area,  std::map <int, RoadParticipant* > roadParticipants );

	Simulation(int top, int left);

	~Simulation();
	///Method to drawing crossing's signs
	void drawSigns(std::map<int, std::map<int, RoadElement*> >area);
	///building map1
	void initialize1();
	///building map2
	void initialize2();
	///building map3
	void initialize3();
	/** The main loop of simulation, iteratiation by every
	 * roadParticipant */
	void simulate();
	///Deleting objects created on previous map
	void end();

	void setRun(bool now);

	bool isRun();

	void pause();
};

#endif
