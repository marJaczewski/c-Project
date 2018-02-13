// ---------------------------------------------------------------------------

#ifndef ElementH
#define ElementH

// #include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>

// #include "Simulation.h"

// ---------------------------------------------------------------------------

class Element {

protected:
	int width;
	int height;
	int yPosition;
	int orientation;
	int xPosition;
	String path;
	TImage * image;

public:

	///Method creating graphical representation of objects
	void createImage(int xPosition, int yPosition, int height, int width,
		int orientation);
	///X-coordinate getter
	int getXPosition();
	///Y-coordinate getter
	int getYPosition();
	///Height getter
	int getHeight();
	///Width getter
	int getWidth();
	///Rotation angle of object getter
	int getOrientation();
	///Rotation angle of object setter
	void setOrientation(int orientation);

};
#endif
