//---------------------------------------------------------------------------

#pragma hdrstop
#include "Enemy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Enemy::setTextureAndNumber(TTexture* texture,int num){
   this->_texture = texture;
   this->number=num;
}

