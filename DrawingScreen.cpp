//---------------------------------------------------------------------------

#pragma hdrstop

#include "DrawingScreen.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <Graphics.hpp>
#include <vcl.h>

TDrawingScreen::TDrawingScreen(TImage* image) {
	this->_image = image;
    this->_imageBuf = new Graphics::TBitmap;
}
void TDrawingScreen::MoveTo(const Coords c) {
	this->_imageBuf->Canvas->MoveTo(c.x,c.y);
}
void TDrawingScreen::LineTo(const Coords c) {
	this->_imageBuf->Canvas->LineTo(c.x,c.y);
}
void TDrawingScreen::DrawLine(const Vector2 vec, const TColor col) {
	TColor prevCol = this->_imageBuf->Canvas->Pen->Color;
	this->_imageBuf->Canvas->Pen->Color = col;
	this->MoveTo(vec.from);
	this->LineTo(vec.to);
	this->_imageBuf->Canvas->Pen->Color = prevCol;
}
void TDrawingScreen::DrawRect(const Vector2 vec, const TColor colBounds, const TColor colIn) {
	TColor prevPenCol = this->_imageBuf->Canvas->Pen->Color;
	TColor prevBrushCol = this->_imageBuf->Canvas->Brush->Color;
	this->_imageBuf->Canvas->Pen->Color = colBounds;
	this->_imageBuf->Canvas->Brush->Color = colIn;
	this->_imageBuf->Canvas->Rectangle(vec.from.x,vec.from.y,vec.to.x,vec.to.y);
	this->_imageBuf->Canvas->Pen->Color = prevPenCol;
	this->_imageBuf->Canvas->Brush->Color = prevBrushCol;
}
void TDrawingScreen::Draw() {
    this->_image->Canvas->Draw(0,0,this->_imageBuf);
}
