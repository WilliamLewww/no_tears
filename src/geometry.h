#pragma once
#include "vector2.h"

class RectangleGL {
private:
	Vector2 position;
	int width, height;

	int color[3];
public:
	RectangleGL(Vector2 position, int width, int height, int color[4]);
	void render();
};