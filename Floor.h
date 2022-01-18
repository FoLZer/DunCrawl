#pragma once

//---------------------------------------------------------------------------

#ifndef FloorH
#define FloorH
//---------------------------------------------------------------------------
#endif

#include "Cell.h"

class Floor : public Cell {
public:
	Floor(Coords _loc);
	void DoRender(TDrawingScreen* Screen,int x,int y,int width,int height);
};