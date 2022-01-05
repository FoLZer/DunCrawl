#pragma once

//---------------------------------------------------------------------------

#ifndef CellObjectH
#define CellObjectH
//---------------------------------------------------------------------------
#endif

#include "Cell.h"
#include "Utils.h"

class CellObject {
protected:
    Cell* loc;
public:
	CellObject(Cell* _loc);
	~CellObject();
    Cell* getLoc();
};
