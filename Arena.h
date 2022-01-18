#pragma once
//---------------------------------------------------------------------------
#ifndef ArenaH
#define ArenaH
//---------------------------------------------------------------------------
#endif
#include "World.h"

class Arena : public TWorld {
 std::vector<bool> fire_exist;
 CellObject* fire;
public:
 using TWorld::TWorld;
 void CreateArena();
 void StartStep();
 void EndStep();
};