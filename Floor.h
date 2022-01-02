#pragma once

//---------------------------------------------------------------------------

#ifndef FloorH
#define FloorH
//---------------------------------------------------------------------------
#endif

#include "Cell.h"
#include "Texture.h"

class Floor : public Cell {
private:
	TTexture* texture;
public:
	Floor();
	void setTexture(TTexture* _texture);
	TTexture* getTexture();
    void DoRender(TDrawingScreen* Screen,int x,int y,int width,int height);
};