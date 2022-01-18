#pragma once
//---------------------------------------------------------------------------

#ifndef WorldH
#define WorldH
//---------------------------------------------------------------------------
#endif

#include <queue>

#include "Cell.h"
#include "CellObject.h"
#include "Floor.h"
#include "Water.h"
#include "Wall.h"
#include "Bridge.h"

#include "Utils.h"
#include "TextureStorage.h"
#include "DrawingScreen.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

class TWorld {
private:
	int width;
	int height;
	int Key_Number;
	std::vector<CellObject*> objects;
	std::vector<Coords> key_coords;
	Player* player;
	template<class T> T* createObject(Cell* loc);
protected:
	std::vector<Cell*> _world;
	int LocToArI(const int x, const int y);
public:
	TWorld();
	~TWorld();
	TTextureStorage *TextureStorage;
	void InitializeWorld(const int width, const int height);
	bool check_objects(Coords l);
	virtual Coords PopulateStartArea();
	Cell* getCellByLoc(Coords loc);
	Cell* getCellByLoc(const int x, const int y);
	void DrawFrame(TDrawingScreen* Screen);
	void SetupPlayer(Coords coords);
	void SetupEnemy(Coords coords,int type);
	void SetupKey(Coords coords);
	int Check_Key_Player();
	int Keys_Left();
    int Keys_Number();
	void MovePlayer(int r_x, int r_y);
    void ChangePlayerTexture(int num);
    Player* getPlayer();
};
