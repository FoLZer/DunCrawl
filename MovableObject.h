#pragma once

//---------------------------------------------------------------------------

#ifndef MovableObjectH
#define MovableObjectH
//---------------------------------------------------------------------------
#endif

#include "Cell.h"
#include "CellObject.h"

class MovableObject : public CellObject {
public:
    using CellObject::CellObject;
	void MoveTo(Cell* _loc);
};
