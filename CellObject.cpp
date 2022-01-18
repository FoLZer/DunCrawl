//---------------------------------------------------------------------------

#pragma hdrstop

#include "CellObject.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

CellObject::CellObject(Cell* _loc) {
    this->loc = _loc;
}

CellObject::~CellObject() {

}

Cell* CellObject::getLoc() {
    return this->loc;
}

int CellObject::getMarker() {
    return this->marker;
}

void CellObject::DoRender(TDrawingScreen* Screen,int x,int y,int width,int height) {
    Screen->DrawTexture({{x,y},{x+width,y+height}}, this->_texture);
}

void CellObject::setTexture(TTexture* texture) {
    this->_texture = texture;
}
