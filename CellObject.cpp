//---------------------------------------------------------------------------

#pragma hdrstop

#include "CellObject.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

CellObject::CellObject(Cell* _loc) {
    this->loc = _loc;
}

Cell* CellObject::getLoc() {
    return this->loc;
}
