#pragma once
//---------------------------------------------------------------------------

#ifndef ArenaH
#define ArenaH
//---------------------------------------------------------------------------
#endif

#include "World.h"

class Arena : public TWorld {
private:
	std::vector<Coords> fire_exist_p;
	std::vector<Coords> fire_exist_e;
	CellObject* fire;
	Enemy* enemy;
    template<class T> T* createObject(Cell* loc);
public:
	using TWorld::TWorld;
	Coords PopulateStartArea();
	void StartStep(Coords d);
    void SetupFire(Coords d);
	void SetupEnemy(Coords coords,int type);
	void EndStep();
};