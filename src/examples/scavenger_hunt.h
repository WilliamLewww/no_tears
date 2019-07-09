#pragma once
#include "../geometry.h"
#include "../input.h"

class ScavengerHunt {
private:
public:
	void initialize(GLuint* shaderProgramHandleArray);
	void update(Input* input, float elapsedTimeS);
	void render();

	void quit();
};