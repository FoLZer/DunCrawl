//---------------------------------------------------------------------------

#ifndef TextureStorageH
#define TextureStorageH
//---------------------------------------------------------------------------
#endif

#include <vcl.h>
#include "Texture.h"
#include <map>

class TTextureStorage {
private:
	std::map<String, TTexture*> textures;
public:
	TTextureStorage();
    ~TTextureStorage();
	void DefineTexture(const String name, const String path);
    void UndefineTexture(const String name);
	void LoadTexture(const String name);
	void UnloadTexture(const String name);
	void LoadAllTextures();
	void UnloadAllTextures();
	TTexture* GetTexture(const String name);
};
