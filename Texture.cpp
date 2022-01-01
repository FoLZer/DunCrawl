//---------------------------------------------------------------------------

#pragma hdrstop

#include "Texture.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TTexture::TTexture(const String _texturePath) {
	this->texturePath = _texturePath;
}

void TTexture::Load() {
	this->imageBitmap = new Graphics::TBitmap;
	this->imageBitmap->LoadFromFile(this->texturePath);
	this->_isLoaded = true;
}

void TTexture::Unload() {
	delete this->imageBitmap;
	this->_isLoaded = false;
}

bool TTexture::isLoaded() {
    return this->_isLoaded;
}
