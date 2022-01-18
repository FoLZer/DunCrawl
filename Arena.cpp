//---------------------------------------------------------------------------

#pragma hdrstop

#include "Arena.h"
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include "Floor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
const int x_dir[]={-1,1,0,0};
const int y_dir[]={0,0,-1,1};

Coords Arena::PopulateStartArea() {
	InitializeWorld(5,4);
	for(int i=0;i<5;i++) {
		for(int j=0;j<4;j++) {
			Cell* c = new Floor({j,i});
			c->setTexture(this->TextureStorage->GetTexture("StoneFloor"));
			int a = this->LocToArI(j,i);
			this->_world[a] = c;
		}
	}
    return {1,1};
}

void Arena::SetupFire(Coords d){
	 Floor* floor = static_cast<Floor*>(this->getCellByLoc(d));
	 fire = this->createObject<MovableObject>(floor);
	 fire->setTexture(this->TextureStorage->GetTexture("Fire1"));
}

template<class T> T* Arena::createObject(Cell* loc) {
	T* obj = new T(loc);
	int n = this->objects.capacity();
	this->objects.reserve(objects.capacity() + 1);
	this->objects.push_back(obj);
	return obj;
}

void Arena::StartStep(Coords d) {
  fire_exist_p.push_back(d);
  for(int i=0;i<4;i++){
	 if(x_dir[i]+d.x>=0 && y_dir[i]+d.y>=0)
	 {
		  Coords f;
		  f.x = x_dir[i]+d.x;
		  f.y = y_dir[i]+d.y;
		  fire_exist_p.push_back(f);
	 }
  }
  for(int i=0;i<fire_exist_p.size();i++)
  {
	  SetupFire(fire_exist_p[i]);
  }
}

void Arena::SetupEnemy(Coords coords,int type){
	Floor* floor = static_cast<Floor*>(this->getCellByLoc(coords));
	enemy = this->createObject<Enemy>(floor);
    switch (type){
	case 1:{
	enemy->setMaxHealth(80);
	enemy->setHealth(80);
	enemy->setTextureAndNumber(this->TextureStorage->GetTexture("Enemy1"),1);
	break;
	}
	case 2:{
	enemy->setMaxHealth(140);
	enemy->setHealth(140);
	enemy->setTextureAndNumber(this->TextureStorage->GetTexture("Enemy2"),2);
	break;
	}
	case 3:{
	enemy->setMaxHealth(40);
	enemy->setHealth(40);
	enemy->setTextureAndNumber(this->TextureStorage->GetTexture("Enemy3"),3);
	break;
	}
	case 4:{
	enemy->setMaxHealth(40);
	enemy->setHealth(40);
	enemy->setTextureAndNumber(this->TextureStorage->GetTexture("Enemy4"),4);
	break;
	}
	case 5:{
	enemy->setMaxHealth(120);
	enemy->setHealth(120);
	enemy->setTextureAndNumber(this->TextureStorage->GetTexture("Enemy5"),5);
	break;
	}
	default:{
	  break;
	}
	}
}

void Arena::EndStep() {
	 srand(time(NULL));
	 Coords d;
	 d.x=rand()%5;
	 int a=d.x;
	 for(int i=0;i<4;i++){
	 d.y=i;
	 SetupFire(d);
	 fire_exist_e.push_back(d);
	 }
	 d.y=rand()%4;
	 for(int i=0;i<5;i++){
	 d.x=i;
	 SetupFire(d);
	 fire_exist_e.push_back(d);
	 }
	 d.x = a;
	 Coords f;
	 f.x=rand()%5;
	 f.y=rand()%4;
	 while(f.x==d.x || f.y==d.y)
	 {
     f.x=rand()%5;
	 f.y=rand()%4;
	 }
	 //enemy->MoveTo()
}
