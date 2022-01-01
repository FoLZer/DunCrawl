//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	this->DrawScreen = new TDrawingScreen(Screen);
	this->TextureStorage = new TTextureStorage();
	this->InitializeTextures();
	this->DrawScreen->DrawRect({{500,500},{599,599}},clBlack,clRed); // Debug rect
    this->DrawScreen->Draw();
}
//---------------------------------------------------------------------------

void TMainForm::InitializeTextures() {
	//Add textures here
	//this->TextureStorage->DefineTexture("Texture1", "path/to/texture/Texture1");
}
