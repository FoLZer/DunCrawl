//---------------------------------------------------------------------------

#ifndef WallH
#define WallH
//---------------------------------------------------------------------------
#endif

#include "Cell.h"

class Wall : public Cell {
public:
	Wall(Coords _loc);
    void DoRender(TDrawingScreen* Screen,int x,int y,int width,int height);
};