#pragma once

struct Coords {
	int x;
	int y;
	//Coords(){x=0;y=0;}
	//Coords(int x_,int y_): x(x_),y(y_){}
};
struct Vector2 {
	Coords from;
	Coords to;
};

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
