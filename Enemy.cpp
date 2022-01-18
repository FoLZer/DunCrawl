//---------------------------------------------------------------------------

#pragma hdrstop

#include "Enemy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Enemy::Enemy(Cell* _loc) : Entity(_loc) {}

Enemy::~Enemy(){}

void Enemy::setTextureAndNumber(TTexture* texture,int num){
	this->setTexture(texture);
   	this->number=num;
}

void Enemy::setNumber(int num){
	this->number=num;
}
int Enemy::getNumber(){
   	return this->number;
}

