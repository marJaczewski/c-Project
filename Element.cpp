// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Element.h"
#include "Unit1.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
extern TForm1 *Form1;

void Element::createImage(int xPosition, int yPosition, int height, int width,
	int orientation) {

	this->image = new TImage(Form1);
	this->image->Parent = Form1;

	// this-> image ->BringToFront();
	this->image->Bitmap->LoadFromFile(this->path);
	this->image->Position->X = xPosition;
	this->image->Position->Y = yPosition;
	this->image->Visible = true;

	this->image->Height = height;
	this->image->Width = width;
	this->image->RotationAngle = orientation;

}

int Element::getXPosition() {

	return this->xPosition;
}

int Element::getYPosition() {

	return this->yPosition;
}

int Element::getHeight() {

	return this->width;
}

int Element::getWidth() {

	return this->height;
}

int Element::getOrientation() {
	return this->orientation;
}

void Element::setOrientation(int orientation) {
	this->orientation = orientation;
}
