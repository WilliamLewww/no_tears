#include "geometry.h"

Geometry::Geometry(std::vector<GLuint>* shaderProgramList) {
	this->shaderProgramList = shaderProgramList;
}

RectangleGL::RectangleGL(Geometry* geometry, Vector2 position, int width, int height, int color[4]) {
	this->geometry = geometry;
	
	this->position = position;
	this->width = width;
	this->height = height;

	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];
	this->color[3] = color[3];
}

void RectangleGL::render() {

}