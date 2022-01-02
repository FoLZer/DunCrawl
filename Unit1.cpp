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
	this->InitializeWorld();
	this->InitializeTextures();
	this->LoadTextures();
    this->World->InitializeWorld(3,3);
	this->World->PopulateStartArea();
    this->World->DrawFrame(this->DrawScreen);

	this->DrawScreen->Draw();
}
//---------------------------------------------------------------------------

void TMainForm::InitializeTextures() {
	//Define textures here
	this->World->TextureStorage->DefineTexture("Wood", "textures/Wood.bmp");
}

void TMainForm::LoadTextures() {
    //Load textures here
	this->World->TextureStorage->LoadTexture("Wood");
}

void TMainForm::InitializeWorld() {
    this->World = new TWorld();
}
