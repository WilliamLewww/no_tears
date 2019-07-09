#pragma once
#include "../geometry.h"

class NoTears {
private:
	RectangleTextured* rectangleList;
public:
	void initialize(GLuint* shaderProgramHandleArray, GLuint* textureHandleArray);
	void update(float elapsedTimeS);
	void render();

	void quit();
};