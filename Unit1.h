
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
#include "Unit2.h"
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
	TMenuItem *Wizard1;
	TTimer *Timer1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall N150x1501Click(TObject *Sender);
	void __fastcall N200x2001Click(TObject *Sender);
	void __fastcall N300x3001Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall Knight1Click(TObject *Sender);
	void __fastcall Rogue2Click(TObject *Sender);
	void __fastcall Rogue1Click(TObject *Sender);
	void __fastcall Wizard1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
	TDrawingScreen *DrawScreen;
	TWorld *World;
	int delay;
	bool game_finished;
	void InitializeTextures();
	void LoadTextures();
	void InitializeWorld();
	void DrawFrame();
	void CreateWorld(int size);
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
	int player_type;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
