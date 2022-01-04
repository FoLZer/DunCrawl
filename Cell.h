#pragma once

//---------------------------------------------------------------------------

#ifndef CellH
#define CellH
//---------------------------------------------------------------------------
#endif

#define PASSABLE 1

#include "DrawingScreen.h"

class Cell {
protected:
	Coords loc;
	TTexture* texture;
    uint8_t properties;
public:
	Cell(Coords _loc);
    Coords getLoc();
	virtual void DoRender(TDrawingScreen* Screen,int x,int y,int width,int height) {}
	virtual bool isPassable();
	void setTexture(TTexture* _texture);
	TTexture* getTexture();
};