//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

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
	this->CreateWorld(64);
}
//---------------------------------------------------------------------------

void TMainForm::DrawFrame() {
	this->World->DrawFrame(this->DrawScreen);
	Player* p = this->World->getPlayer();
	int health = p->getHealth();
	int maxHealth = p->getMaxHealth();
	this->DrawScreen->DrawText({10,10}, clRed,"HP: "+IntToStr(health)+" / "+IntToStr(maxHealth));
	this->DrawScreen->Draw();
}

void TMainForm::CreateWorld(int size) {
	this->World->InitializeWorld(size,size);
	Coords c = this->World->PopulateStartArea();
	this->World->SetupPlayer(c);
	this->DrawFrame();
}

void TMainForm::InitializeTextures() {
	//Define textures here
	this->World->TextureStorage->DefineTexture("StoneWall", "textures/StoneWall.bmp");
	this->World->TextureStorage->DefineTexture("StoneFloor", "textures/StoneFloor.bmp");
	this->World->TextureStorage->DefineTexture("Water", "textures/Water.bmp");
	this->World->TextureStorage->DefineTexture("Background", "textures/Back.bmp");
	this->World->TextureStorage->DefineTexture("Bridge", "textures/Bridge.bmp");
	this->World->TextureStorage->DefineTexture("Knight_skin", "textures/Knight_skin.bmp", true);
}

void TMainForm::LoadTextures() {
	//Load textures here
	this->World->TextureStorage->LoadTexture("StoneWall");
	this->World->TextureStorage->LoadTexture("StoneFloor");
	this->World->TextureStorage->LoadTexture("Water");
	this->World->TextureStorage->LoadTexture("Background");
	this->World->TextureStorage->LoadTexture("Bridge");
	this->World->TextureStorage->LoadTexture("Knight_skin");
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
		this->DrawFrame();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N150x1501Click(TObject *Sender)
{
	this->CreateWorld(150);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N200x2001Click(TObject *Sender)
{
	this->CreateWorld(200);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N300x3001Click(TObject *Sender)
{
	this->CreateWorld(300);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
