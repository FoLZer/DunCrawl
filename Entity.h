#pragma once

//---------------------------------------------------------------------------

#ifndef EntityH
#define EntityH
//---------------------------------------------------------------------------
#endif

#include "MovableObject.h"

class Entity : public MovableObject {
private:
	int health;
	int maxHealth;
	//armor,etc...
public:
	Entity(Cell* _loc);
	~Entity();
	int getHealth();
	void setHealth(int _health);
	int getMaxHealth();
	void setMaxHealth(int _maxHealth);
};
