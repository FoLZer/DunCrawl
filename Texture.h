//---------------------------------------------------------------------------

#ifndef TextureH
#define TextureH
//---------------------------------------------------------------------------
#endif


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
