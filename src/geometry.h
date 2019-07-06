#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "external_context.h"

class RectangleBasic {
private:
	GLuint vaoHandle;
	GLuint vboHandles[1];
	GLuint positionBufferHandle;
	GLuint colorLocationHandle;
	GLuint resolutionLocationHandle;

	glm::vec4 color;

	GLuint* shaderProgramHandle;
public:
	void initialize(GLuint* shaderProgramHandle);
	void render();
};