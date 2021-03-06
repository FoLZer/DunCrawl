#pragma once
//---------------------------------------------------------------------------

#ifndef WorldH
#define WorldH
//---------------------------------------------------------------------------
#endif

#include <vector>
#include "Utils.h"
#include "CellObject.h"
#include "Player.h"
#include "TextureStorage.h"
#include "Enemy.h"

class TWorld {
private:
	int Key_Number;
	std::vector<Coords> key_coords;
protected:
	std::vector<CellObject*> objects;
	std::vector<Cell*> _world;
	int LocToArI(const int x, const int y);
    int width;
	int height;
	Player* player;
public:
	TWorld();
	~TWorld();
    template<class T> T* createObject(Cell* loc);
	TTextureStorage *TextureStorage;
	void InitializeWorld(const int width, const int height);
	int check_objects(Coords l);
	virtual Coords PopulateStartArea();
	Cell* getCellByLoc(Coords loc);
	Cell* getCellByLoc(const int x, const int y);
	virtual void DrawFrame(TDrawingScreen* Screen);
	void SetupPlayer(Coords coords);
	void SetupEnemy(Coords coords,int type);
	void SetupKey(Coords coords);
	int Check_Key_Player();
	int Keys_Left();
	int Keys_Number();
	void setPlayerHP(int a);
	virtual void MovePlayer(int r_x, int r_y);
	void ChangePlayerTexture(int num);
	Player* getPlayer();
};
