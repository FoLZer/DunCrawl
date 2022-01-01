//---------------------------------------------------------------------------

#ifndef DrawingScreenH
#define DrawingScreenH
//---------------------------------------------------------------------------
#endif

class TDrawingScreen
{
private:
	TImage* _image;
	Graphics::TBitmap* _imageBuf;
	void Draw();
	void MoveTo(const Coords c);
	void LineTo(const Coords c);
	void DrawLine(const Vector2 vec, const TColor col);
	void DrawRect(const Vector2 vec, const TColor colBounds, const TColor colIn);
public:
	TDrawingScreen(TImage* image);
};