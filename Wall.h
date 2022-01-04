//---------------------------------------------------------------------------

#ifndef WallH
#define WallH
//---------------------------------------------------------------------------
#endif

#include "Cell.h"

class Wall : public Cell {
public:
	bool isWall();
	using Cell::Cell;
    void DoRender(TDrawingScreen* Screen,int x,int y,int width,int height);
};