//---------------------------------------------------------------------------
#pragma hdrstop
#include "World.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <ctime>

const int CHUNK_SIZE = 64;

TWorld::TWorld() {
	this->TextureStorage = new TTextureStorage();
}
TWorld::~TWorld() {
	for(Cell* c : this->_world) {
		delete c;
	}
	this->_world.clear();
}
Cell* TWorld::getCellByLoc(Coords loc) {
	return this->getCellByLoc(loc.x, loc.y);
}
Cell* TWorld::getCellByLoc(const int x, const int y) {
	return this->_world[this->LocToArI(x,y)];
}
int TWorld::LocToArI(const int x, const int y) {
	return x * this->width + y;
}
Coords TWorld::PopulateStartArea() {
	int amount_=17, size_=2;
	char map_[CHUNK_SIZE][CHUNK_SIZE];
	int seed = time(NULL);
	srand(seed);
	for(int i=0; i<CHUNK_SIZE; i++) {
		srand(rand());
		for(int j=0; j<CHUNK_SIZE; j++) {
			int probability1=0;

			if(i<8||i>CHUNK_SIZE-9||j<8||j>CHUNK_SIZE-9) {
				if((rand()%10!=2)&&(i==7||i==CHUNK_SIZE-9)&&(j==7||j==CHUNK_SIZE-9)) {
					map_[i][j]='f';
				} else {
					map_[i][j]='w';
				}
			} else {
				probability1+=amount_;
				if(j>2&&i>2) {
					int b=(map_[i-1][j-1]==map_[i][j-1])+(map_[i-1][j-1]==map_[i-2][j-1])+(map_[i-1][j-1]==map_[i-1][j-2])+(map_[i-1][j-1]==map_[i-1][j]);
					if(b<2) {
						if(map_[i-1][j-1]=='f') {
							map_[i-1][j-1]='w';
						} else {
							map_[i-1][j-1]='f';
						}
					}
				}
				probability1+=((map_[i-1][j]=='f')+(map_[i][j-1]=='f')+(map_[i-1][j+1]=='f'))*(19+size_*1.4);
				if(rand()%101<probability1) {
					map_[i][j]='w';
				} else {
					map_[i][j]='f';
				}
			}
		}
	}
	for(int i=1; i<CHUNK_SIZE-1; i++) {
		for(int j=1; j<CHUNK_SIZE-1; j++) {
			if(map_[i][j]=='w'&&((map_[i][j+1]=='f'&&map_[i][j-1]=='f')||(map_[i+1][j]=='f'&&map_[i-1][j]=='f'))) {
				map_[i][j]='a';
			}
		}
	}
	Coords coords;
	for(int i = 0;i<CHUNK_SIZE;i++) {
		for(int i1 = 0;i1<CHUNK_SIZE;i1++) {
			Cell* c;
			switch(map_[i][i1]) {
				case 'w': {
					c = new Wall({i1,i});
					c->setTexture(this->TextureStorage->GetTexture("StoneWall"));
					break;
				}
				case 'a': {
					c = new Floor({i1,i});
					c->setTexture(this->TextureStorage->GetTexture("StoneFloor"));
					if(i<90&&i1<110) {
						coords.x = i1;
						coords.y = i;
					}
					break;
				}
				case 'f': {
					c = new Water({i1,i});
					c->setTexture(this->TextureStorage->GetTexture("Water"));
					break;
				}
				default: {
					continue;
				}
			}
			int a = this->LocToArI(i1,i);
			this->_world[a] = c;
		}
	}
	return coords;
}
void TWorld::InitializeWorld(const int _width, const int _height) {
	this->width = _width;
	this->height = _height;
	this->_world.resize(_width * _height);
}
void TWorld::DrawFrame(TDrawingScreen* Screen) {
	Cell* centerCell = this->player->getLoc();
	Coords centerLoc = centerCell->getLoc();
	Screen->Clear();
	Screen->DrawTextureRepeat({{centerLoc.x*4,centerLoc.y*4},{Screen->getWidth(),Screen->getHeight()}},this->TextureStorage->GetTexture("Background"));
	for(int x=0;x<this->width;x++) {
		for(int y=0;y<this->height;y++) {
			Cell* c = this->getCellByLoc(x,y);
			if(c == NULL) {
				continue;
			}
			c->DoRender(Screen,50*(x-centerLoc.x)+Screen->getWidth()/2-25,50*(y-centerLoc.y)+Screen->getHeight()/2-25,50,50);
		}
	}
}
void TWorld::SetupPlayer(Coords coords) {
	Floor* floor = static_cast<Floor*>(this->getCellByLoc(coords.x,coords.y));
	this->player = this->createObject<Player>(floor);
}
template<class T> T* TWorld::createObject(Cell* loc) {
	T* obj = new T(loc);
	int n = this->objects.size();
	this->objects.reserve(n+1);
	this->objects[n] = obj;
	return obj;
}
void TWorld::MovePlayer(int r_x, int r_y) {
	Cell* curCel = this->player->getLoc();
	Coords curLoc = curCel->getLoc();
	Cell* c;
	int new_x = std::max(std::min(curLoc.x+r_x,this->width-1),0);
	while((c = this->getCellByLoc(new_x,curLoc.y)) != NULL && !c->isPassable()) {
		int s = -sgn(r_x);
		new_x += s == 0 ? 1 : s;
	}
	int new_y = std::max(std::min(curLoc.y+r_y,this->height-1),0);
	while((c = this->getCellByLoc(curLoc.x,new_y)) != NULL && !c->isPassable()) {
		int s = -sgn(r_y);
		new_y += s == 0 ? 1 : s;
	}
	c = this->getCellByLoc(new_x, new_y);
	if(c == NULL) {
		return;
	}
	this->player->MoveTo(c);
}

