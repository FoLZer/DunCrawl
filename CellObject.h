#pragma once

//---------------------------------------------------------------------------

#ifndef CellObjectH
#define CellObjectH
//---------------------------------------------------------------------------
#endif

#include "Cell.h"

class CellObject {
private:
	Cell* loc;
public:
	CellObject();
	~CellObject();
	void MoveTo(Cell* cell);
};
