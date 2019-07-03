#pragma once
#include <vector>
#include <GLFW/glfw3.h>
#include "vector2.h"

class Geometry {
private:
	std::vector<GLuint>* shaderProgramList;
public:
	Geometry(std::vector<GLuint>* shaderProgramList);
};

class RectangleGL {
private:
	Geometry* geometry;

	Vector2 position;
	int width, height;

	int color[3];
public:
	RectangleGL(Geometry* geometry, Vector2 position, int width, int height, int color[4]);
	void render();
};