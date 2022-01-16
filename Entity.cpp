//---------------------------------------------------------------------------

#pragma hdrstop

#include "Entity.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Entity::Entity(Cell* _loc) : MovableObject(_loc) {}

int Entity::getHealth() {
	return this->health;
}

int Entity::getMaxHealth() {
	return this->maxHealth;
}

void Entity::setMaxHealth(int _maxHealth) {
	this->maxHealth = _maxHealth;
}

void Entity::setHealth(int _health) {
    this->health = _health;
}
