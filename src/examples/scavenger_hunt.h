#pragma once
#include "../geometry.h"

class ScavengerHunt {
private:
public:
	void initialize(GLuint* shaderProgramHandleArray);
	void update(float elapsedTimeS);
	void render();

	void quit();
};