//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>

#include <map>
//---------------------------------------------------------------------------
struct Coords {
	int x;
	int y;
};
struct Vector2 {
	Coords from;
	Coords to;
};
//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
class TTextureStorage {
private:
	std::map<String, TTexture> textures;
public:
	TTextureStorage();
	void DefineTexture(String name, String path);
	void LoadTexture(String name);
	void UnloadTexture(String name);
	void LoadAllTextures();
	void UnloadAllTextures();
};
//---------------------------------------------------------------------------
class TDrawingScreen
{
private:
	TImage* _image;
	Graphics::TBitmap* _imageBuf;
	void Draw();
	void MoveTo(const Coords c);
	void LineTo(const Coords c);
	void DrawLine(const Vector2 vec, const TColor col);
	void DrawRect(const Vector2 vec, const TColor colBounds, const TColor colIn);
public:
	TDrawingScreen(TImage* image);
};
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Screen;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
    TDrawingScreen *DrawScreen;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
