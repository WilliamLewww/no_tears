#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "external_context.h"
#include "vector2.h"

class RectangleBasic {
private:
	int width, height;

	glm::vec4 color;

	GLuint vaoHandle;
	GLuint vboHandles[1];
	GLuint positionBufferHandle;

	GLuint resolutionLocationHandle;
	GLuint colorLocationHandle;

	GLuint shaderProgramHandle;

	float* getPositionVertexData();
public:
	Vector2 position;

	inline void setColor(int r, int g, int b, int a) {
		color = glm::vec4(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}

	void initialize(GLuint shaderProgramHandle, Vector2 position, int width, int height);
	void render();
};

class RectangleTextured {
private:
	int width, height;
	GLuint textureHandle;

	GLuint vaoHandle;
	GLuint vboHandles[2];
	GLuint positionBufferHandle;
	GLuint textureBufferHandle;

	GLuint resolutionLocationHandle;
	GLuint textureSamplerLocationHandle;

	GLuint shaderProgramHandle;

	float* getPositionVertexData();
	float* getTextureVertexData();
public:
	Vector2 position;

	void initialize(GLuint shaderProgramHandle, GLuint textureHandle, Vector2 position, int width, int height);
	void render();
};