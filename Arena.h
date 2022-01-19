#pragma once
//---------------------------------------------------------------------------

#ifndef ArenaH
#define ArenaH
//---------------------------------------------------------------------------
#endif

#include "World.h"
#include "Utils.h"

#include "Cell.h"
#include "CellObject.h"
#include "Floor.h"
#include "Water.h"
#include "Wall.h"
#include "Bridge.h"

#include "TextureStorage.h"
#include "DrawingScreen.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

class TArena : public TWorld {
private:
	std::vector<Coords> fire_exist_p;
	std::vector<Coords> fire_exist_e;
	CellObject* fire;
	Enemy* enemy;
	int result;
public:
	using TWorld::TWorld;
	Coords PopulateStartArea();
	void StartStep(Coords d);
    void SetupFire(Coords d);
	void SetupEnemy(Coords coords,int type);
	void NPCStep();
	void DMGCalculating();
	Coords getEnemyHealth();
	void set_result(int i);
	int get_result();
    void DrawFrame(TDrawingScreen* Screen);
};