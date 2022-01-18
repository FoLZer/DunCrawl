//---------------------------------------------------------------------------

#pragma hdrstop

#include "Arena.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

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

void Arena::StartStep() {

}

void Arena::EndStep() {

}
