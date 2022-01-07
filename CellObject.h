#pragma once

//---------------------------------------------------------------------------

#ifndef CellObjectH
#define CellObjectH
//---------------------------------------------------------------------------
#endif

#include "Cell.h"
#include "Utils.h"

class CellObject {
private:
	TTexture* _texture;
protected:
	Cell* loc;
public:
	CellObject(Cell* _loc);
	~CellObject();
	Cell* getLoc();
	void DoRender(TDrawingScreen* Screen,int x,int y,int width,int height);
	void setTexture(TTexture* texture);
};
