//---------------------------------------------------------------------------

#pragma hdrstop

#include "MovableObject.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void MovableObject::MoveTo(Cell* _loc) {
    this->loc = _loc;
}
