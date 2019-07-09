#pragma once
#include "../geometry.h"
#include "../input.h"

class ScavengerHunt {
private:
	RectangleBasic* rectangleList;
	int rectangleCount;
	
	int rectangleSize;
public:
	void initialize(GLuint* shaderProgramHandleArray);
	void update(Input* input, float elapsedTimeS);
	void render();

	void quit();
};