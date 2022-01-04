#pragma once

//---------------------------------------------------------------------------

#ifndef FloorH
#define FloorH
//---------------------------------------------------------------------------
#endif

#include "CellObject.h"
#include "Cell.h"
#include "Texture.h"

class Floor : public Cell {
public:
	Floor(Coords _loc);
	void DoRender(TDrawingScreen* Screen,int x,int y,int width,int height);
};