//---------------------------------------------------------------------------

#ifndef TextureH
#define TextureH
//---------------------------------------------------------------------------
#endif

#include <vcl.h>


class TTexture {
private:
	bool _isLoaded = false;
	String texturePath;
	Graphics::TBitmap* imageBitmap;
public:
	TTexture(const String _texturePath);
    ~TTexture();
	void Load();
	void Unload();
    bool isLoaded();
};
