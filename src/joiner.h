#pragma once
#include "geometry.h"

class Joiner {
private:
	RectangleGL* rectangle;
public:
	void initialize();
	void update();
	void render();
};