//---------------------------------------------------------------------------
#pragma hdrstop
#include "World.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <queue>

#include "Bridge.h"
#include "Floor.h"
#include "Wall.h"
#include "Water.h"

int CHUNK_SIZE = 64;
const int CELL_SIZE = 50;

const int x_bfs[]{-1,1,0,0};
const int y_bfs[]{0,0,-1,1};

TWorld::TWorld() {
	this->TextureStorage = new TTextureStorage();
}
TWorld::~TWorld() {
	for(Cell* c : this->_world) {
		delete c;
	}
	this->_world.clear();
	this->objects.clear();
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

int TWorld::check_objects(Coords coords){
	 for(int i=0;i<objects.size();i++){
		for (int j=0;j<4;j++)
		  if(objects[i]->getLoc()->getLoc().x + x_bfs[j] == coords.x && objects[i]->getLoc()->getLoc().y + y_bfs[j] == coords.y)
			{
			if(objects[i]->getMarker()!=0)
				{
				int a=objects[i]->getMarker();
				objects.erase(objects.begin()+i);
				i--;
				return a;
				}
			}
	 }
	 return -2;
}

void TWorld::setPlayerHP(int a){
	player->setHealth(a);
	return;
}

Coords TWorld::PopulateStartArea() {
	int amount_ = 17, size_ = 2;
	std::vector<std::vector<char>> map_(CHUNK_SIZE, std::vector<char>(CHUNK_SIZE, 'w'));
	int seed = time(NULL);
	srand(seed);
	for(int i=0; i < CHUNK_SIZE; i++) {
		srand(rand());
		for(int j=0; j < CHUNK_SIZE; j++) {
			int probability1 = 0;

			if(i < 8 || i > CHUNK_SIZE - 9 || j < 8 || j > CHUNK_SIZE - 9) {
				if((rand() % 10 != 2) && (i == 7 || i == CHUNK_SIZE - 9) && (j == 7 || j == CHUNK_SIZE - 9)) {
					map_[i][j] = 'f';
				} else {
					map_[i][j] = 'w';
				}
			} else {
				probability1 += amount_;
				if(j > 2 && i > 2) {
                    int b = 0;
                    b += map_[i - 1][j - 1] == map_[i][j - 1];
                    b += map_[i - 1][j - 1] == map_[i - 2][j - 1];
                    b += map_[i - 1][j - 1] == map_[i - 1][j - 2];
                    b += map_[i - 1][j - 1] == map_[i - 1][j];
					if(b < 2) {
						if(map_[i - 1][j - 1] == 'f') {
							map_[i - 1][j - 1] = 'w';
						} else {
							map_[i - 1][j - 1] = 'f';
						}
					}
				}
                int a = 0;
                a += map_[i - 1][j] == 'f';
                a += map_[i][j - 1] == 'f';
                a += map_[i - 1][j + 1] == 'f';
				probability1 += a * (19 + size_ * 1.4);
				if(rand() % 101 < probability1) {
					map_[i][j] = 'w';
				} else {
					map_[i][j] = 'f';
				}
			}
		}
	}
	std::vector<std::vector<int>> map_reductor(CHUNK_SIZE, std::vector<int>(CHUNK_SIZE,0));
	for(int i=0; i < CHUNK_SIZE - 1; i++) {
        for(int j=0; j < CHUNK_SIZE - 1; j++) {
            switch(map_[i][j]) {
                case 'w': {
                    map_reductor[i][j] = -9;
                    break;
                }
                case 'a': {
                    map_reductor[i][j] = -9;
                    break;
                }
                case 'f': {
                    map_reductor[i][j] = -1;
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }
    std::queue <Coords> bfs;
    Coords xy1,xy2;
    xy1.x = CHUNK_SIZE / 2;
    xy1.y = CHUNK_SIZE / 2;
    bfs.push(xy1);
    while(map_reductor[xy1.x][xy1.y] != -1) {
        xy1 = bfs.front();
        for(int i=0; i<4; i++) {
            xy2.x = xy1.x + x_bfs[i];
            xy2.y = xy1.y + y_bfs[i];
            bfs.push(xy2);
        }
		bfs.pop();
    }
    while(!bfs.empty()) {
        bfs.pop();
    }
    bfs.push(xy1);
    map_reductor[xy1.x][xy1.y] = -2;
    while(!bfs.empty()) {
        xy2.y = bfs.front().y;
        xy2.x = bfs.front().x;
        bfs.pop();
        for(int i=0; i<4; i++) {
            xy1.x = xy2.x + x_bfs[i];
            xy1.y = xy2.y + y_bfs[i];
            if(map_reductor[xy1.x][xy1.y] == -1) {
                map_reductor[xy1.x][xy1.y] = -2;
                bfs.push(xy1);
            }
        }
    }
	for(int ist = 4; ist<CHUNK_SIZE - 6; ist++) {
		for(int jst = 4; jst<CHUNK_SIZE - 6; jst++) {
            if(map_reductor[ist][jst] == -1) {
                xy1.x = ist;
                xy1.y = jst;
                bfs.push(xy1);
                map_reductor[ist][jst] = 0;
                int square = 0;
                std::queue <Coords> closer_walls;
                while(!bfs.empty()) {
                    xy1.x = bfs.front().x;
                    xy1.y = bfs.front().y;
                    bfs.pop();
                    for(int i = 0; i < 4; i++) {
                        int k = map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]];
                        if(k == -1) {
                            map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]] = 0;
                            xy2.x = xy1.x + x_bfs[i];
                            xy2.y = xy1.y + y_bfs[i];
                            bfs.push(xy2);
                            square++;
                        } else {
                            if(k == -9) {
                                map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]] = 1;
                                xy2.x = xy1.x + x_bfs[i];
                                xy2.y = xy1.y + y_bfs[i];
                                closer_walls.push(xy2);
                            }
                        }
                    }
                }
                if(square < 5) {
                    for(int i = 7; i < CHUNK_SIZE-7; i++) {
                        for(int j = 7; j < CHUNK_SIZE-7; j++) {
                            switch(map_reductor[i][j]) {
                                case 0: {
                                    map_reductor[i][j]=-9;
                                    map_[i][j]='w';
                                    break;
                                }
                                case 1: {
                                    map_reductor[i][j]=-9;
                                    break;
                                }
                                default: {
                                    break;
                                }
                            }
                        }
                    }
                } else {
                    int Flag = 123;
                    while(Flag == 123) {
                        xy1 = closer_walls.front();
                        closer_walls.pop();

                        for(int i = 0; i < 4; i++) {
                            if(xy1.x == 0 || xy1.y == 0 || xy1.y == CHUNK_SIZE-1 || xy1.x == CHUNK_SIZE-1) {
                                continue;
                            } else {
                                switch(map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]]) {
                                    case -9: {
                                        xy2.x = xy1.x + x_bfs[i];
                                        xy2.y = xy1.y + y_bfs[i];
                                        closer_walls.push(xy2);
                                        map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]] = map_reductor[xy1.x][xy1.y] + 1;
                                        break;
                                    }
                                    case -1: {
                                        Flag = -1;
                                        break;
                                    }
                                    case -2: {
                                        Flag = -2;
                                        break;
                                    }
                                    default: {
                                        break;
                                    }
                                }
                            }
                            if(Flag != 123) {
                                break;
                            }
						}
					}
					while(!closer_walls.empty()) {
                        closer_walls.pop();
                    }
                    int way = map_reductor[xy1.x][xy1.y];
					while(map_reductor[xy1.x][xy1.y] != 0) {
                        int x_add = 0;
                        int y_add = 0;
                        for(int i = 0; i < 4; i++)
                        {
                            if(map_reductor[xy1.x][xy1.y]-1 == map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]] && x_add == 0 && y_add == 0) {
                                x_add = x_bfs[i];
                                y_add = y_bfs[i];
                            } else {
								switch(map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]]) {
									case 0:
									case -1:
									case -2:
									case -3: {
                                        break;
                                    }
                                    default: {
                                        xy2.x = xy1.x + x_bfs[i];
                                        xy2.y = xy1.y + y_bfs[i];
                                        if(map_reductor[xy2.x][xy2.y] < way+1) {
                                            closer_walls.push(xy2);
                                            map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]] = way + 3;
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                        map_reductor[xy1.x][xy1.y] = -3;
                        xy1.x += x_add;
                        xy1.y += y_add;
                    }
                    while(!closer_walls.empty()) {
                        xy1.x = closer_walls.front().x;
                        xy1.y = closer_walls.front().y;
						if(map_reductor[xy1.x][xy1.y] < way + 5 && map_reductor[xy1.x][xy1.y] > way + 1) {
                            for(int i = 0; i < 4; i++) {
                                switch(map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]]) {
                                    case -9: {
                                        xy2.x = xy1.x + x_bfs[i];
                                        xy2.y = xy1.y + y_bfs[i];
                                        closer_walls.push(xy2);
                                        map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]] = map_reductor[xy1.x][xy1.y] + 1;
                                        break;
									}
									case 0:
									case -1:
									case -2:
									case -3: {
                                        break;
                                    }
                                    default: {
                                        if(way + 1 > map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]]) {
                                            xy2.x = xy1.x + x_bfs[i];
                                            xy2.y = xy1.y + y_bfs[i];
                                            closer_walls.push(xy2);
											map_reductor[xy1.x + x_bfs[i]][xy1.y + y_bfs[i]] = map_reductor[xy1.x][xy1.y] + 1;
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                        closer_walls.pop();
                    }
                    for(int i = 0; i < CHUNK_SIZE - 1; i++) {
                        for(int j = 0; j < CHUNK_SIZE - 1; j++) {
                            switch(map_reductor[i][j]) {
                                case 0: {
                                    map_reductor[i][j]=Flag;
                                    break;
								}
								case -1:
								case -2:
                                case -9: {
                                    break;
                                }
                                case -3: {
                                    map_[i][j] = 'b';
                                    map_reductor[i][j] = Flag;
                                    break;
                                }
                                default: {
                                    if(map_reductor[i][j] > way + 1)
                                    {
                                        map_[i][j] = 'a';
                                    }
                                    map_reductor[i][j] = -9;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
	}
	Coords coords;
	std::queue <Coords> enemy_place;
	int number_of_keys=0;
	for(int i = 0;i < CHUNK_SIZE;i++) {
		for(int i1 = 0;i1 < CHUNK_SIZE;i1++) {
			Cell* c;
			switch(map_[i][i1]) {
				case 'b': {
					c = new Bridge({i1,i});
					c->setTexture(this->TextureStorage->GetTexture("Bridge"));
					bool FLag=false;
					if(number_of_keys<6){
					 FLag=true;
					 for(int j=0;j<key_coords.size();j++){
					   if(sqrt((key_coords[j].x - i1)*(double)(key_coords[j].x - i1) + (key_coords[j].y - i)*(key_coords[j].y - i))<CHUNK_SIZE/5)
					   {
							 FLag=false;
							 break;
					   }
					 }
					}
					if(FLag){
					key_coords.push_back({i1,i});
                    number_of_keys++;
					}else{
                    if(i < CHUNK_SIZE / 1.8 && i1 < CHUNK_SIZE / 1.8) {
								coords.x = i1;
								coords.y = i;
							 }
					}
					break;
				}
				case 'w': {
					c = new Wall({i1,i});
					c->setTexture(this->TextureStorage->GetTexture("StoneWall"));
					break;
				}
				case 'f': {
					c = new Floor({i1,i});
					c->setTexture(this->TextureStorage->GetTexture("StoneFloor"));
					bool Flag=true;
					if(number_of_keys<6){
					 for(int j=0;j<key_coords.size();j++){
					   if(sqrt((key_coords[j].x - i1)*(double)(key_coords[j].x - i1) + (key_coords[j].y - i)*(key_coords[j].y - i))<CHUNK_SIZE/2.85)
					   {
							 Flag=false;
							 break;
					   }
					 }
					 if((number_of_keys>3) && (i<CHUNK_SIZE*0.66))
					 {Flag=false;}
					}
					if(Flag==true && number_of_keys<6 && (rand()%20>17)){
					   number_of_keys++;
					   key_coords.push_back({i1,i});
					   break;
					}
					Flag=true;
					if(!enemy_place.empty()){
					   Coords checker, locker;
					   checker.y = i1;
					   checker.x = i;
					   locker = enemy_place.front();
					   enemy_place.pop();
					   enemy_place.push(locker);
					   while(enemy_place.front().x != locker.x && enemy_place.front().y != locker.y)
					   {
							if (!((abs(enemy_place.front().x - checker.x) > 1) || (abs(enemy_place.front().y  - checker.y) > 1)))
								{Flag = false;}
							enemy_place.push(enemy_place.front());
							enemy_place.pop();
					   }
					}else{
					   Flag=true;
					}
					if(Flag==true)
					{
					   int counter = (map_[i][i1-1]== 'a') + (map_[i][i1+1] == 'a') + (map_[i-1][i1] == 'a') +
					   (map_[i+1][i1] == 'a') + (map_[i][i1-1] == 'w')+(map_[i][i1+1] == 'w') + (map_[i-1][i1] == 'w') +
					   (map_[i+1][i1] == 'w');
					   switch (counter) {
						case 0:{
						counter=5;
						break;
						}
						case 1:{
						counter=6;
						break;
						}
						case 2:{
						counter=20;
						break;
						}
						case 3:{
						counter=56;
						break;
						}
					   }
					   if(counter>rand()%101)
					   {
						Coords dx;
						dx.x = i1;
						dx.y = i;
						enemy_place.push(dx);
					   }
					   else
					   {
                         if(i < CHUNK_SIZE / 1.8 && i1 < CHUNK_SIZE / 1.8) {
						  coords.x = i1;
						  coords.y = i;
						 }
					   }
					}
					break;
				}
				case 'a': {
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
	for(int i=0;i<key_coords.size();i++){
		SetupKey(key_coords[i]);
	}
	Key_Number = key_coords.size();
	while(!enemy_place.empty())
	{
	   if((abs(enemy_place.front().x - coords.x) > 1) || (abs(enemy_place.front().y  - coords.y) > 1))
	   SetupEnemy(enemy_place.front(),rand() % 5 + 1);
	   enemy_place.pop();
	}
	return coords;
}

void TWorld::SetupKey(Coords coords)
{
	 Floor* d = static_cast<Floor*>(this->getCellByLoc(coords.x,coords.y));
	 CellObject* key = this->createObject<CellObject>(d);
	 key->setTexture(this->TextureStorage->GetTexture("Key"));
}
int TWorld::Check_Key_Player(){
	for(int i=0;i<key_coords.size();i++){
		if(key_coords[i].x==player->getLoc()->getLoc().x && key_coords[i].y==player->getLoc()->getLoc().y)
		{
		   objects.erase(objects.begin()+i);
		   key_coords.erase(key_coords.begin()+i);
		   return i;
		}
	}
	return -1;
}
int TWorld::Keys_Left(){
	return key_coords.size();
}

int TWorld::Keys_Number(){
	return Key_Number;
}

void TWorld::InitializeWorld(const int _width, const int _height) {
	this->width = _width;
	this->height = _height;
	for(int i=0;i<this->objects.size();i++) {
		if(this->objects[i] != NULL) {
			delete this->objects[i];
		}
	}
	this->objects.clear();
	this->objects.shrink_to_fit();
	for(int i=0;i<this->_world.size();i++) {
		if(this->_world[i] != NULL) {
			delete this->_world[i];
		}
    }
	this->_world.clear();
	this->_world.resize(_width * _height);
	CHUNK_SIZE = _width;
}
void TWorld::DrawFrame(TDrawingScreen* Screen) {
	Cell* centerCell = this->player->getLoc();
	Coords centerLoc = centerCell->getLoc();
	Screen->Clear();
	Screen->DrawTextureRepeat({{centerLoc.x*4,centerLoc.y*4},{Screen->getWidth(),Screen->getHeight()}},this->TextureStorage->GetTexture("Background"));
	for(int x=std::max(centerLoc.x-7,0);x<=std::min(centerLoc.x+7,this->width-1);x++) {
		for(int y=std::max(centerLoc.y-7,0);y<=std::min(centerLoc.y+7,this->height-1);y++) {
			Cell* c = this->getCellByLoc(x,y);
			if(c == NULL) {
				continue;
			}
			c->DoRender(Screen,CELL_SIZE*(x-centerLoc.x)+Screen->getWidth()/2-(CELL_SIZE/2),CELL_SIZE*(y-centerLoc.y)+Screen->getHeight()/2-(CELL_SIZE/2),CELL_SIZE,CELL_SIZE);
		}
	}
	for(int i = 0; i < this->objects.capacity(); i++) {
		CellObject* obj = this->objects[i];
		Coords loc = obj->getLoc()->getLoc();
		if(std::abs(loc.x - centerLoc.x) < 8 && std::abs(loc.y - centerLoc.y) < 8) {
			obj->DoRender(Screen,CELL_SIZE*(loc.x-centerLoc.x)+Screen->getWidth()/2-(CELL_SIZE/2),CELL_SIZE*(loc.y-centerLoc.y)+Screen->getHeight()/2-(CELL_SIZE/2),CELL_SIZE,CELL_SIZE);
		}
	}
}

void TWorld::SetupPlayer(Coords coords) {
	Floor* floor = static_cast<Floor*>(this->getCellByLoc(coords.x,coords.y));
	this->player = this->createObject<Player>(floor);
	this->player->setMaxHealth(100);
	this->player->setHealth(100);
	this->player->setTexture(this->TextureStorage->GetTexture("Wizard_skin"));
}

void TWorld::SetupEnemy(Coords coords,int type){
	Floor* d = static_cast<Floor*>(this->getCellByLoc(coords.x,coords.y));
	/// NEED TO REWRITE FUNCTION, THAT ADDS ENEMIES CORRECTLY
	Enemy* current_enemy = this->createObject<Enemy>(d);
	switch (type){
	case 1:{

	current_enemy->setMaxHealth(80);
	current_enemy->setHealth(80);
	//current_enemy->setTexture(this->TextureStorage->GetTexture("Enemy1"));
	current_enemy->setTextureAndNumber(this->TextureStorage->GetTexture("Enemy1"),1);
	break;
	}
	case 2:{
	current_enemy->setMaxHealth(140);
	current_enemy->setHealth(140);
	//current_enemy->setTexture(this->TextureStorage->GetTexture("Enemy2"));
	current_enemy->setTextureAndNumber(this->TextureStorage->GetTexture("Enemy2"),2);
	break;
	}
	case 3:{
	current_enemy->setMaxHealth(40);
	current_enemy->setHealth(40);
	//current_enemy->setTexture(this->TextureStorage->GetTexture("Enemy3"));
	current_enemy->setTextureAndNumber(this->TextureStorage->GetTexture("Enemy3"),3);
	break;
	}
	case 4:{
	current_enemy->setMaxHealth(40);
	current_enemy->setHealth(40);
	//current_enemy->setTexture(this->TextureStorage->GetTexture("Enemy4"));
	current_enemy->setTextureAndNumber(this->TextureStorage->GetTexture("Enemy4"),4);
	break;
	}
	case 5:{
	current_enemy->setMaxHealth(120);
	current_enemy->setHealth(120);
	//current_enemy->setTexture(this->TextureStorage->GetTexture("Enemy5"));
	current_enemy->setTextureAndNumber(this->TextureStorage->GetTexture("Enemy5"),5);
	break;
	}
	default:{
	  break;
	}
	}
}

template<class T> T* TWorld::createObject(Cell* loc) {
	T* obj = new T(loc);
	int n = this->objects.capacity();
	this->objects.reserve(objects.capacity() + 1);
	this->objects.push_back(obj);
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

Player* TWorld::getPlayer() {
	return this->player;
}

void TWorld::ChangePlayerTexture (int num){
	switch (num){
	case 1:{
	//set knight texture
	this->player->setTexture(this->TextureStorage->GetTexture("Knight_skin"));
	break;
	}
	case 2:{
	//set elf texture
	this->player->setTexture(this->TextureStorage->GetTexture("Elf_skin"));
	break;
	}
	case 3:{
	//set Mario texture
	this->player->setTexture(this->TextureStorage->GetTexture("Mario_skin"));
	break;
	}
	case 4:{
	//set Wizard texture
	this->player->setTexture(this->TextureStorage->GetTexture("Wizard_skin"));
	break;
	}
	}
}

void TWorld::EraseObjectsTillEnd(int b){
   while(objects.size()>b)
   {objects.erase(objects.begin()+b);}
}

