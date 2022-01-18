#pragma once

//---------------------------------------------------------------------------

#ifndef CellObjectH
#define CellObjectH
//---------------------------------------------------------------------------
#endif

#include "Cell.h"

class CellObject {
private:
	TTexture* _texture;
protected:
	Cell* loc;
    int marker=0;
public:
	CellObject(Cell* _loc);
	~CellObject();
	Cell* getLoc();
	int getMarker();
	void DoRender(TDrawingScreen* Screen,int x,int y,int width,int height);
	void setTexture(TTexture* texture);
};
