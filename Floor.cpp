//---------------------------------------------------------------------------

#pragma hdrstop

#include "Floor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Floor::DoRender(TDrawingScreen* Screen,int x,int y,int width,int height) {
	Screen->DrawTexture({{x,y},{x+width,y+height}}, this->texture);
}
