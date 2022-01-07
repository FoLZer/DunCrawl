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
	TMenuItem *N1;
	TMenuItem *Saveprogress1;
	TMenuItem *Downloadprogress1;
	TMenuItem *Downloadprogress2;
	TMenuItem *Exit1;
	TMenuItem *Settings1;
	TMenuItem *LandSize1;
	TMenuItem *N150x1501;
	TMenuItem *N200x2001;
	TMenuItem *N300x3001;
	TMenuItem *PoVskin1;
	TMenuItem *Rogue1;
	TMenuItem *Rogue2;
	TMenuItem *Knight1;
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
