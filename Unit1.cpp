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
	game_finished = false;
	this->CreateWorld(54);
	delay = 0;
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void TMainForm::DrawFrame() {
	this->World->DrawFrame(this->DrawScreen);
	Player* p = this->World->getPlayer();
	int health = p->getHealth();
	int maxHealth = p->getMaxHealth();
	this->DrawScreen->DrawText({10,10}, clRed, 15,"HP: "+IntToStr(health)+" / "+IntToStr(maxHealth));
	this->DrawScreen->DrawText({10,35}, clYellow, 15,"Keys: "+IntToStr(this->World->Keys_Number() - this->World->Keys_Left())+" / "+IntToStr(this->World->Keys_Number()));
	if(game_finished){
	this->DrawScreen->DrawText({10,100}, clBlue, 85,"   Game");
	this->DrawScreen->DrawText({10,210}, clBlue, 85,"  finished");
	}
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
	this->World->TextureStorage->DefineTexture("Elf_skin", "textures/Elf_skin.bmp", true);
	this->World->TextureStorage->DefineTexture("Mario_skin", "textures/Mario_skin.bmp", true);
	this->World->TextureStorage->DefineTexture("Wizard_skin", "textures/Wizard_skin.bmp", true);
	this->World->TextureStorage->DefineTexture("Enemy1", "textures/Enemy1.bmp", true);
	this->World->TextureStorage->DefineTexture("Enemy2", "textures/Enemy2.bmp", true);
	this->World->TextureStorage->DefineTexture("Enemy3", "textures/Enemy3.bmp", true);
	this->World->TextureStorage->DefineTexture("Enemy4", "textures/Enemy4.bmp", true);
	this->World->TextureStorage->DefineTexture("Enemy5", "textures/Enemy5.bmp", true);
	this->World->TextureStorage->DefineTexture("Key", "textures/Key.bmp", true);
}
void TMainForm::LoadTextures() {
	//Load textures here
	this->World->TextureStorage->LoadTexture("StoneWall");
	this->World->TextureStorage->LoadTexture("StoneFloor");
	this->World->TextureStorage->LoadTexture("Water");
	this->World->TextureStorage->LoadTexture("Background");
	this->World->TextureStorage->LoadTexture("Bridge");
	this->World->TextureStorage->LoadTexture("Knight_skin");
	this->World->TextureStorage->LoadTexture("Elf_skin");
	this->World->TextureStorage->LoadTexture("Mario_skin");
	this->World->TextureStorage->LoadTexture("Wizard_skin");
	this->World->TextureStorage->LoadTexture("Enemy1");
	this->World->TextureStorage->LoadTexture("Enemy2");
	this->World->TextureStorage->LoadTexture("Enemy3");
	this->World->TextureStorage->LoadTexture("Enemy4");
	this->World->TextureStorage->LoadTexture("Enemy5");
	this->World->TextureStorage->LoadTexture("Key");
}
void TMainForm::InitializeWorld() {
	this->World = new TWorld();
}
void __fastcall TMainForm::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	bool redraw = false;
	if(delay>1 && (!game_finished)){
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
		delay=0;
	}
	if(redraw) {
        int a=0;
		while(a!=-2)
		{
		   a=this->World->check_objects(this->World->getPlayer()->getLoc()->getLoc());
		   if(a!=-2)
		   {
		      Form2->Show();
			  Form2->Label1->Caption=IntToStr(player_type);
			  Form2->Label2->Caption=IntToStr(this->World->getPlayer()->getHealth());
			  buld=-20;
			  while(buld == -20){
			  MainForm->Enabled = false;
			  }
			  MainForm->Enabled = true;
			  this->World->setPlayerHP(this->World->getPlayer()->getHealth()-1);
		   }
		}
		int t =this->World->Check_Key_Player();
		if(this->World->Keys_Left()==0)
		{
			game_finished=true;
		}
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
void __fastcall TMainForm::Knight1Click(TObject *Sender)
{
	 this->World->ChangePlayerTexture(1);
	 this->DrawFrame();
	 this->player_type = 1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Rogue2Click(TObject *Sender)
{
	 this->World->ChangePlayerTexture(3);
	 this->DrawFrame();
	 this->player_type = 3;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Rogue1Click(TObject *Sender)
{
	 this->World->ChangePlayerTexture(2);
	 this->DrawFrame();
	 this->player_type = 2;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Wizard1Click(TObject *Sender)
{
	 this->World->ChangePlayerTexture(4);
	 this->DrawFrame();
	 this->player_type = 4;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
	  delay++;
	  if(delay > 100)
	  delay = 10;
}
//---------------------------------------------------------------------------
