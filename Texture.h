//---------------------------------------------------------------------------

#ifndef TextureH
#define TextureH
//---------------------------------------------------------------------------
#endif

#include <vcl.h>


class TTexture {
private:
	bool isLoaded = false;
	String texturePath;
	Graphics::TBitmap* imageBitmap;
public:
	TTexture(String _texturePath);
	void Load();
    void Unload();
};
