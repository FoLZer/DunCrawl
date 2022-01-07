//---------------------------------------------------------------------------

#pragma hdrstop
#include "Bridge.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Bridge::Bridge(Coords _loc) : Cell(_loc) {
	this->properties |= PASSABLE;
}
void Bridge::DoRender(TDrawingScreen* Screen,int x,int y,int width,int height) {
	Screen->DrawTexture({{x,y},{x+width,y+height}}, this->texture);
}