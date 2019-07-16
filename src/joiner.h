#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "examples/no_tears.h"
#include "examples/scavenger_hunt.h"
#include "examples/lighting_test.h"
#include "input.h"

enum class EXAMPLE_FLAG { NO_TEARS, SCAVENGER_HUNT, LIGHTING_TEST };

class Joiner {
private:
	EXAMPLE_FLAG currentExample = EXAMPLE_FLAG::LIGHTING_TEST;

	NoTears* noTears;
	ScavengerHunt* scavengerHunt;
	LightingTest* lightingTest;
public:
	void initialize(GLuint* shaderProgramHandleArray, GLuint* textureHandleArray);
	void update(Input* input, float elapsedTimeS);
	void render();

	void quit();
};