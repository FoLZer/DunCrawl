#pragma once

//---------------------------------------------------------------------------

#ifndef CellH
#define CellH
//---------------------------------------------------------------------------
#endif

#include "Utils.h"
#include "DrawingScreen.h"

class Cell {
private:
	Coords loc;
public:
	Cell();
	Coords getLoc();
	void setLoc(Coords _loc);
    virtual void DoRender(TDrawingScreen* Screen,int x,int y,int width,int height) {}
};