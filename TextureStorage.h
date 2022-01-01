//---------------------------------------------------------------------------

#ifndef TextureStorageH
#define TextureStorageH
//---------------------------------------------------------------------------
#endif


#include <map>

class TTextureStorage {
private:
	std::map<String, TTexture> textures;
public:
	TTextureStorage();
	void DefineTexture(const String name, const String path);
	void LoadTexture(const String name);
	void UnloadTexture(const String name);
	void LoadAllTextures();
	void UnloadAllTextures();
};
