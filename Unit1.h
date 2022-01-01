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
