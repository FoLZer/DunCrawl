#pragma once
//---------------------------------------------------------------------------
#ifndef BridgeH
#define BridgeH
#endif
//---------------------------------------------------------------------------
#include "CellObject.h"
#include "Cell.h"
#include "Texture.h"
class Bridge : public Cell {
public:
	Bridge(Coords _loc);
    void DoRender(TDrawingScreen* Screen,int x,int y,int width,int height);
};
