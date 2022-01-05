//---------------------------------------------------------------------------

#pragma hdrstop

#include "Wall.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Wall::Wall(Coords _loc) : Cell(_loc) {
}

void Wall::DoRender(TDrawingScreen* Screen,int x,int y,int width,int height) {
	Screen->DrawTexture({{x,y},{x+width,y+height}}, this->texture);
}
