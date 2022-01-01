//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TDrawingScreen::TDrawingScreen(TImage* image) {
	this->_image = image;
    this->_imageBuf = new Graphics::TBitmap;
}
void TDrawingScreen::MoveTo(Coords c) {
	this->_imageBuf->Canvas->MoveTo(c.x,c.y);
}
void TDrawingScreen::LineTo(Coords c) {
	this->_imageBuf->Canvas->LineTo(c.x,c.y);
}
void TDrawingScreen::DrawLine(Vector2 vec, TColor col) {
	TColor prevCol = this->_imageBuf->Canvas->Pen->Color;
	this->_imageBuf->Canvas->Pen->Color = col;
	this->MoveTo(vec.from);
	this->LineTo(vec.to);
	this->_imageBuf->Canvas->Pen->Color = prevCol;
}
void TDrawingScreen::Draw() {
    this->_image->Canvas->Draw(0,0,this->_imageBuf);
}
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
	MainForm -> DrawScreen = new TDrawingScreen(Screen);
}
//---------------------------------------------------------------------------
