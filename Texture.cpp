//---------------------------------------------------------------------------

#pragma hdrstop

#include "Texture.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TTexture::TTexture(const String _texturePath) {
	this->texturePath = _texturePath;
}
TTexture::TTexture(const String _texturePath, const bool isTransparent) {
	this->texturePath = _texturePath;
	this->_isTransparent = isTransparent;
}

TTexture::~TTexture() {
	if(this->_isLoaded) {
		delete this->imageBitmap;
    }
}

void TTexture::Load() {
	if(this->_isLoaded) {
		throw "Tried to load Texture without unloading previous one!";
	}
	this->imageBitmap = new Graphics::TBitmap;
	if(this->_isTransparent) {
		this->imageBitmap->TransparentColor = clWhite;
		this->imageBitmap->Transparent = true;
	}
	this->imageBitmap->LoadFromFile(this->texturePath);
	this->_isLoaded = true;
}

void TTexture::Unload() {
	if(this->_isLoaded) {
        delete this->imageBitmap;
		this->_isLoaded = false;
	}
}

bool TTexture::isLoaded() {
    return this->_isLoaded;
}

Graphics::TBitmap* TTexture::getBitmap() {
	if(!this->isLoaded()) {
		throw "Tried to get unloaded bitmap from texture!";
	}
	return this->imageBitmap;
}
