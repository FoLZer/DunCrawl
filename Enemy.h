#pragma once

//---------------------------------------------------------------------------
#ifndef EnemyH
#define EnemyH
//---------------------------------------------------------------------------
#endif

#include "Cell.h"
#include "CellObject.h"
#include "Entity.h"

class Enemy : public Entity {
	int number;
	public:
	Enemy(Cell* _loc);
	~Enemy();
	void setNumber(int num);
	int getNumber();
	void setTextureAndNumber(TTexture* texture,int num);
};
