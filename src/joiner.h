#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "examples/no_tears.h"
#include "examples/scavenger_hunt.h"

class Joiner {
private:
	NoTears* noTears;
public:
	void initialize(GLuint* shaderProgramHandleArray, GLuint* textureHandleArray);
	void update(float elapsedTimeS);
	void render();

	void quit();
};