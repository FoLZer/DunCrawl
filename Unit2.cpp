//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm2::InitializeTextures() {
	//Define textures here
			this->Arena->TextureStorage->DefineTexture("Arena_cell", "textures/Arena_cell.bmp");
        	this->Arena->TextureStorage->DefineTexture("Arena_cell_blured", "textures/Arena_cell_blured.bmp");
        	this->Arena->TextureStorage->DefineTexture("StoneWall", "textures/StoneWall.bmp");
        	this->Arena->TextureStorage->DefineTexture("StoneFloor", "textures/StoneFloor.bmp");
        	this->Arena->TextureStorage->DefineTexture("Water", "textures/Water.bmp");
        	this->Arena->TextureStorage->DefineTexture("Background", "textures/Back.bmp");
        	this->Arena->TextureStorage->DefineTexture("Bridge", "textures/Bridge.bmp");
        	this->Arena->TextureStorage->DefineTexture("Knight_skin", "textures/Knight_skin.bmp", true);
        	this->Arena->TextureStorage->DefineTexture("Elf_skin", "textures/Elf_skin.bmp", true);
        	this->Arena->TextureStorage->DefineTexture("Mario_skin", "textures/Mario_skin.bmp", true);
        	this->Arena->TextureStorage->DefineTexture("Wizard_skin", "textures/Wizard_skin.bmp", true);
        	this->Arena->TextureStorage->DefineTexture("Enemy1", "textures/Enemy1.bmp", true);
        	this->Arena->TextureStorage->DefineTexture("Enemy2", "textures/Enemy2.bmp", true);
        	this->Arena->TextureStorage->DefineTexture("Enemy3", "textures/Enemy3.bmp", true);
			this->Arena->TextureStorage->DefineTexture("Enemy4", "textures/Enemy4.bmp", true);
			this->Arena->TextureStorage->DefineTexture("Enemy5", "textures/Enemy5.bmp", true);
			this->Arena->TextureStorage->DefineTexture("Fire1", "textures/Fire1.bmp", true);
}
void TForm2::LoadTextures() {
	//Load textures here
			this->Arena->TextureStorage->LoadTexture("Arena_cell");
        	this->Arena->TextureStorage->LoadTexture("Arena_cell_blured");
        	this->Arena->TextureStorage->LoadTexture("StoneWall");
        	this->Arena->TextureStorage->LoadTexture("StoneFloor");
        	this->Arena->TextureStorage->LoadTexture("Water");
        	this->Arena->TextureStorage->LoadTexture("Background");
        	this->Arena->TextureStorage->LoadTexture("Bridge");
        	this->Arena->TextureStorage->LoadTexture("Knight_skin");
        	this->Arena->TextureStorage->LoadTexture("Elf_skin");
        	this->Arena->TextureStorage->LoadTexture("Mario_skin");
        	this->Arena->TextureStorage->LoadTexture("Wizard_skin");
        	this->Arena->TextureStorage->LoadTexture("Enemy1");
        	this->Arena->TextureStorage->LoadTexture("Enemy2");
        	this->Arena->TextureStorage->LoadTexture("Enemy3");
			this->Arena->TextureStorage->LoadTexture("Enemy4");
			this->Arena->TextureStorage->LoadTexture("Enemy5");
			this->Arena->TextureStorage->LoadTexture("Fire1");
}
void __fastcall TForm2::FormCreate(TObject *Sender)
{
    this->Arena = new TArena();
	this->DrawScreen = new TDrawingScreen(this->Image1);
	this->InitializeTextures();
	this->LoadTextures();
	stady=0;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	Coords d;
	d.x = X/50;
	d.y = Y/50;
	switch (stady){
		case 0: {
			this->Arena->MovePlayer(d.x, d.y);
			this->DrawFrame();
			stady = 1;
			break;
		}
		case 1: {
			this->Arena->StartStep(d);
			this->DrawFrame();
			stady = 2;
			break;
		}
		case 2: {
			this->Arena->NPCStep();
			this->DrawFrame();
			stady = 3;
			break;
		}
		case 3: {
			this->Arena->DMGCalculating();
			this->DrawFrame();
			if(this->Arena->get_result()!=0)
			{
				Timer2->Enabled =true;
				int newHP = this->Arena->getPlayer()->getHealth();
				this->Arena->Clear();
				Form2->Hide();
				MainForm->Show();
			   	MainForm->EnableAfterFight(newHP);
			}
			stady = 0;
		}
	}
}

void TForm2::InitNewArena(int playerHP, int enemy_type) {
	this->Arena->PopulateStartArea();
	this->Arena->SetupPlayer({0,1});
    this->Arena->setPlayerHP(playerHP);
	this->Arena->SetupEnemy({3,1},enemy_type);
	stady=0;
	this->Arena->set_result(0);
    this->DrawFrame();
}

//---------------------------------------------------------------------------
void TForm2::DrawFrame()
{
   	this->Arena->DrawFrame(this->DrawScreen);
	int health = this->Arena->getPlayer()->getHealth();
	int maxHealth = this->Arena->getPlayer()->getMaxHealth();
	int en_health = this->Arena->getEnemyHealth().x;
	int en_maxHealth = this->Arena->getEnemyHealth().y;
	this->DrawScreen->DrawText({10,10}, clRed, 15,"HP: "+IntToStr(health)+" / "+IntToStr(maxHealth));
	this->DrawScreen->DrawText({10,110}, clRed, 15,"co: "+IntToStr(this->Arena->getPlayer()->getLoc()->getLoc().x)+" / "+IntToStr(this->Arena->getPlayer()->getLoc()->getLoc().y));
	this->DrawScreen->Draw();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    MainForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
	stady=0;
	this->DrawFrame();
}
//---------------------------------------------------------------------------

