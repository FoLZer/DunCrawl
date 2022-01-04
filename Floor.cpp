//---------------------------------------------------------------------------

#pragma hdrstop

#include "Floor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Floor::setTexture(TTexture* _texture) {
	this->texture = _texture;
}

TTexture* Floor::getTexture() {
	return this->texture;
}

void Floor::DoRender(TDrawingScreen* Screen,int x,int y,int width,int height) {
	Screen->DrawTexture({{x,y},{x+width,y+height}}, this->texture);
}
