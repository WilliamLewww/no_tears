#pragma once
#include <glm/glm.hpp>
#include "../geometry.h"
#include "../input.h"

class CubePhong {
private:
	float* positionVertexData;
	float* normalVertexData;

	glm::mat4 modelMatrix;
	glm::mat4* viewMatrix;
	glm::mat4* projectionMatrix;

	GLuint vaoHandle;
	GLuint vboHandles[2];
	GLuint positionBufferHandle;
	GLuint normalBufferHandle;

	GLuint modelMatrixLocationHandle;
	GLuint viewMatrixLocationHandle;
	GLuint projectionMatrixLocationHandle;

	GLuint shaderProgramHandle;
public:
	void initialize(GLuint shaderProgramHandle, glm::mat4* viewMatrix, glm::mat4* projectionMatrix);
	void render();

	void translate(glm::vec3 translation);
	void rotate(float radians, glm::vec3 axis);
};

class LightingTest {
private:
	glm::mat4 viewMatrix;
	glm::vec3 cameraPosition;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	float cameraPitch;
	float cameraYaw;

	glm::mat4 projectionMatrix;

	CubePhong* cube;
public:
	void initialize(GLuint* shaderProgramHandleArray);
	void update(Input* input, float elapsedTimeS);
	void render();

	void quit();
};