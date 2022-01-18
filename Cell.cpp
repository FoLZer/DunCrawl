//---------------------------------------------------------------------------

#pragma hdrstop

#include "Cell.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Cell::Cell(Coords _loc) {
	this->loc = _loc;
}

Coords Cell::getLoc() {
	return this->loc;
}

void Cell::setCoords(Coords _loc) {
	this->loc = _loc;
}

void Cell::setTexture(TTexture* _texture) {
	this->texture = _texture;
}

TTexture* Cell::getTexture() {
	return this->texture;
}

bool Cell::isPassable() {
	return properties & PASSABLE;
}
