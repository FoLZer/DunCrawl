//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <chrono>
#include <thread>
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
    this->World->InitializeWorld(7,7);
	this->World->PopulateStartArea();
	this->World->SetupPlayer();
	this->World->DrawFrame(this->DrawScreen);
    this->DrawScreen->DrawLine({{Screen->Width/2,0},{Screen->Width/2,Screen->Height}},clBlack);
    this->DrawScreen->DrawLine({{0,Screen->Height/2},{Screen->Width,Screen->Height/2}},clBlack);

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
void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
	this->World->MovePlayer(0,1);
	this->World->DrawFrame(this->DrawScreen);
    this->DrawScreen->DrawLine({{Screen->Width/2,0},{Screen->Width/2,Screen->Height}},clBlack);
    this->DrawScreen->DrawLine({{0,Screen->Height/2},{Screen->Width,Screen->Height/2}},clBlack);
	this->DrawScreen->Draw();
}
//---------------------------------------------------------------------------

