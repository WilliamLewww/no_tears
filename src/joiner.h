#pragma once
#include "geometry.h"

class Joiner {
private:
	RectangleGL* rectangle;
public:
	void initialize(Geometry* geometry);
	void update();
	void render();
};