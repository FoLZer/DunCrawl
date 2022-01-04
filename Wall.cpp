//---------------------------------------------------------------------------

#pragma hdrstop

#include "Wall.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool Wall::isWall() {
    return true;
}

void Wall::DoRender(TDrawingScreen* Screen,int x,int y,int width,int height) {
	Screen->DrawTexture({{x,y},{x+width,y+height}}, this->texture);
}
