// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
// #include<iostream>
#include <map>
#include "Unit1.h"
// #include "RoadElement.h"
#include "Simulation.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

// GraphicsSystem *graphicsSystem = new GraphicsSystem();

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {

}
// ---------------------------------------------------------------------------

// std::map <int, std::map <int, RoadElement* > > area;
// std::map <int, RoadParticipant* > roadParticipants;
// Simulation * simulation = new Simulation(0, 0, area, roadParticipants);

Simulation * simulation = new Simulation(0, 0);

void __fastcall TForm1::StartClick(TObject *Sender) {
	// Form1->Label43->Text=simulation->getAreaSize();

	simulation->end();
	simulation->initialize2();

	simulation->simulate();

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	simulation->end();
	delete simulation;

	exit(0);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	simulation->end();
	simulation->initialize1();
	simulation->simulate();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) {
	simulation->end();
	simulation->initialize3();
	simulation->simulate();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender) {

	if (simulation->isRun() == true) {
		simulation->setRun(false);
	}
	else {
		simulation->setRun(true);
		simulation->simulate();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender) {
	simulation->setRun(true);
	simulation->simulate();
}
// ---------------------------------------------------------------------------
