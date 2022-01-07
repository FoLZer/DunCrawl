#pragma once

//---------------------------------------------------------------------------

#ifndef TextureH
#define TextureH
//---------------------------------------------------------------------------
#endif

#include <vcl.h>


class TTexture {
private:
	bool _isLoaded = false;
	bool _isTransparent = false;
	String texturePath;
	Graphics::TBitmap* imageBitmap;
public:
    TTexture(const String _texturePath);
	TTexture(const String _texturePath, const bool isTransparent);
    ~TTexture();
	void Load();
	void Unload();
	bool isLoaded();
	Graphics::TBitmap* getBitmap();
};
