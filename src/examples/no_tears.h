#pragma once
#include "../geometry.h"

class NoTears {
private:
	RectangleTextured* rectangleList;
	int rectangleCount;

	int* sizeList;
	float* velocityXList;
	float* velocityYList;
public:
	void initialize(GLuint* shaderProgramHandleArray, GLuint* textureHandleArray);
	void update(float elapsedTimeS);
	void render();

	void quit();
};