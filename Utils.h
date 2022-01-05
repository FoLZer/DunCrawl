#pragma once

struct Coords {
	int x;
	int y;
};
struct Vector2 {
	Coords from;
	Coords to;
};

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
