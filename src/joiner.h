#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "geometry.h"

class Joiner {
private:
	RectangleBasic* rectangleList;
public:
	void initialize(GLuint* shaderProgramHandle);
	void update(float elapsedTimeS);
	void render();
};