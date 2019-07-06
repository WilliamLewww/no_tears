#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "external_context.h"
#include "vector2.h"

class RectangleBasic {
private:
	Vector2 position;
	int width, height;

	glm::vec4 color;
	
	GLuint vaoHandle;
	GLuint vboHandles[1];
	GLuint positionBufferHandle;
	GLuint colorLocationHandle;
	GLuint resolutionLocationHandle;

	GLuint* shaderProgramHandle;

	float* getPositionVertexData();
public:
	void initialize(GLuint* shaderProgramHandle, Vector2 position, int width, int height);
	void render();
};