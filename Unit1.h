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

#include "DrawingScreen.h"
#include "World.h"
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Screen;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
	TDrawingScreen *DrawScreen;
    TWorld *World;
	void InitializeTextures();
	void LoadTextures();
    void InitializeWorld();
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
