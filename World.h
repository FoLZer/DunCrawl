#pragma once
//---------------------------------------------------------------------------

#ifndef WorldH
#define WorldH
//---------------------------------------------------------------------------
#endif

#include <vector>

#include "Cell.h"
#include "Floor.h"
#include "Wall.h"
#include "Utils.h"
#include "TextureStorage.h"
#include "DrawingScreen.h"
#include "Player.h"

class TWorld {
private:
    bool isInitialized = false;
	int width;
	int height;
	std::vector<Cell*> _world;
    std::vector<CellObject*> objects;
    Player* player;
	int LocToArI(const int x, const int y);
	template<class T> T* createObject(Cell* loc);
public:
	TWorld();
	~TWorld();
    TTextureStorage *TextureStorage;
    void InitializeWorld(const int width, const int height);
	void PopulateStartArea();
	Cell* getCellByLoc(Coords loc);
	Cell* getCellByLoc(const int x, const int y);
	void DrawFrame(TDrawingScreen* Screen);
	void SetupPlayer();
    void MovePlayer(int r_x, int r_y);
};