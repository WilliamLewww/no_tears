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

	GLuint vaoHandle;
	GLuint vboHandles[1];
	GLuint positionBufferHandle;
	GLuint colorLocationHandle;
	GLuint resolutionLocationHandle;

	float vertexData[12];
	glm::vec4 color;

	GLuint* shaderProgramHandle;

	void setPositionData();
public:
	void initialize(GLuint* shaderProgramHandle, Vector2 position, int width, int height);
	void render();
};