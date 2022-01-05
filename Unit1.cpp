//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <chrono>
#include <thread>

#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

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
    this->World->InitializeWorld(50,50);
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
	this->World->TextureStorage->DefineTexture("Wall", "textures/Wall.bmp");
	this->World->TextureStorage->DefineTexture("Water", "textures/Water.bmp");
}

void TMainForm::LoadTextures() {
    //Load textures here
	this->World->TextureStorage->LoadTexture("Wood");
	this->World->TextureStorage->LoadTexture("Wall");
	this->World->TextureStorage->LoadTexture("Water");
}

void TMainForm::InitializeWorld() {
    this->World = new TWorld();
}

void __fastcall TMainForm::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	bool redraw = false;
	switch(Key) {
		case KEY_UP: {
			this->World->MovePlayer(0,-1);
			redraw = true;
			break;
		}
		case KEY_DOWN: {
			this->World->MovePlayer(0,1);
			redraw = true;
			break;
		}
		case KEY_LEFT: {
			this->World->MovePlayer(-1,0);
			redraw = true;
			break;
		}
		case KEY_RIGHT: {
			this->World->MovePlayer(1,0);
            redraw = true;
			break;
        }
	}
	if(redraw) {
        this->World->DrawFrame(this->DrawScreen);
		this->DrawScreen->DrawLine({{Screen->Width/2,0},{Screen->Width/2,Screen->Height}},clBlack);
		this->DrawScreen->DrawLine({{0,Screen->Height/2},{Screen->Width,Screen->Height/2}},clBlack);
		this->DrawScreen->Draw();
	}
}
//---------------------------------------------------------------------------

