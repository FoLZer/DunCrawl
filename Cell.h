#pragma once

//---------------------------------------------------------------------------

#ifndef CellH
#define CellH
//---------------------------------------------------------------------------
#endif

#include "DrawingScreen.h"

class Cell {
protected:
    Coords loc;
public:
	Cell(Coords _loc);
    Coords getLoc();
    virtual void DoRender(TDrawingScreen* Screen,int x,int y,int width,int height) {}
};