//---------------------------------------------------------------------------

#pragma hdrstop

#include "Cell.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Cell::Cell() {}

Coords Cell::getLoc() {
	return this->loc;
}

void Cell::setLoc(Coords _loc) {
	this->loc = _loc;
}
