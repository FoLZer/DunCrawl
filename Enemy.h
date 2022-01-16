#pragma once

//---------------------------------------------------------------------------
#ifndef EnemyH
#define EnemyH
//---------------------------------------------------------------------------
#endif

#include "Cell.h"
#include "CellObject.h"

class Enemy : public Entity {
	int number;
	public:
	using Entity::Entity;
	void setTextureAndNumber(TTexture* texture,int num);
};
