//---------------------------------------------------------------------------

#pragma hdrstop

#include "World.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

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
	for(int i = 0;i < 3; i++) {
		for(int i1 = 0;i1<3;i1++) {
			Floor* f = new Floor();
			f->setTexture(this->TextureStorage->GetTexture("Wood"));
			int a = this->LocToArI(i,i1);
			this->_world[a] = f;
		}
	}
}

void TWorld::InitializeWorld(const int _width, const int _height) {
    this->width = _width;
	this->height = _height;
	this->_world.reserve(_width * _height);
}

void TWorld::DrawFrame(TDrawingScreen* Screen) {
	for(int x=0;x<this->width;x++) {
		for(int y=0;y<this->height;y++) {
			Cell* c = this->getCellByLoc(x,y);
            c->DoRender(Screen,50*(x+1),50*(y+1),50,50);
		}
    }
}
