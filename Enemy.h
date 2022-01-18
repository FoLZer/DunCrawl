#pragma once

//---------------------------------------------------------------------------

#ifndef EnemyH
#define EnemyH
//---------------------------------------------------------------------------
#endif

#include "Entity.h"
#include "Texture.h"

class Enemy : public Entity {
private:
	int number;
public:
	Enemy(Cell* _loc);
	~Enemy();
	void setNumber(int num);
	int getNumber();
	void setTextureAndNumber(TTexture* texture,int num);
};
