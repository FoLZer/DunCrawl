#pragma once

//---------------------------------------------------------------------------

#ifndef EntityH
#define EntityH
//---------------------------------------------------------------------------
#endif

#include "MovableObject.h"

class Entity : public MovableObject {
	int health;
    int maxHealth;
	//health,armor,etc...
public:
	Entity(Cell* _loc);
	int getHealth();
	void setHealth(int _health);
	int getMaxHealth();
	void setMaxHealth(int _maxHealth);
};