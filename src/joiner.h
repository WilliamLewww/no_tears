#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "geometry.h"

class Joiner {
private:
	RectangleTextured* rectangleList;
public:
	void initialize(GLuint* shaderProgramHandleArray, GLuint* textureHandleArray);
	void update(float elapsedTimeS);
	void render();

	void quit();
};