#pragma once

//---------------------------------------------------------------------------

#ifndef DrawingScreenH
#define DrawingScreenH
//---------------------------------------------------------------------------
#endif

#include <Graphics.hpp>
#include <vcl.h>
#include "Utils.h"

#include "Texture.h"

class TDrawingScreen
{
private:
	TImage* _image;
	Graphics::TBitmap* _imageBuf;
	void MoveTo(const Coords c);
	void LineTo(const Coords c);
public:
	TDrawingScreen(TImage* image);
	~TDrawingScreen();
	int getWidth();
    int getHeight();
	void Draw();
	void DrawLine(const Vector2 vec, const TColor col);
	void DrawRect(const Vector2 vec, const TColor colBounds, const TColor colIn);
	void DrawTexture(const Vector2 bounds, TTexture* texture);
    void Clear();
};