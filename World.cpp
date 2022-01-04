//---------------------------------------------------------------------------

#pragma hdrstop

#include "World.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <algorithm>

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

void TWorld::PopulateStartArea() {
	for(int i = 0;i < 7; i++) {
		for(int i1 = 0;i1<7;i1++) {
			Cell* c;
			if(i == 0 || i1 == 0 || i == 6 || i1 == 6 || (i == 2 && i1 == 4)) {
				c = new Wall({i,i1});
				c->setTexture(this->TextureStorage->GetTexture("Wall"));
			} else {
				c = new Floor({i,i1});
				c->setTexture(this->TextureStorage->GetTexture("Wood"));
			}
			int a = this->LocToArI(i,i1);
			this->_world[a] = c;
		}
	}
}

void TWorld::InitializeWorld(const int _width, const int _height) {
    this->width = _width;
	this->height = _height;
	this->_world.reserve(_width * _height);
}

void TWorld::DrawFrame(TDrawingScreen* Screen) {
    Screen->Clear();
	Cell* centerCell = this->player->getLoc();
    Coords centerLoc = centerCell->getLoc();
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

void TWorld::SetupPlayer() {
	Floor* floor = static_cast<Floor*>(this->getCellByLoc(1,1));
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
	int new_x = std::max(std::min(curLoc.x+r_x,this->width-1),0);
	while(this->getCellByLoc(new_x,curLoc.y)->isWall()) {
		int s = -sgn(r_x);
		new_x += s == 0 ? 1 : s;
	}
	int new_y = std::max(std::min(curLoc.y+r_y,this->height-1),0);
	while(this->getCellByLoc(curLoc.x,new_y)->isWall()) {
		int s = -sgn(r_y);
		new_y += s == 0 ? 1 : s;
	}
	this->player->MoveTo(this->getCellByLoc(new_x, new_y));
}
