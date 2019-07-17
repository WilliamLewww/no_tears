#pragma once
#include <glm/glm.hpp>
#include "../geometry.h"
#include "../input.h"

struct Light {
	glm::vec3 position;
	glm::vec3 color;
};

struct Camera {
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	float pitch;
	float yaw;
};

class CubePhong {
private:
	float* positionVertexData;
	float* normalVertexData;

	glm::vec4 color;

	Camera* camera;
	Light* light;

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

	GLuint colorLocationHandle;

	GLuint lightPositionLocationHandle;
	GLuint lightColorLocationHandle;
	GLuint viewPositionLocationHandle;

	GLuint shaderProgramHandle;
public:
	inline void setColor(int r, int g, int b, int a) {
		color = glm::vec4(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}
	
	void initialize(GLuint shaderProgramHandle, glm::mat4* viewMatrix, glm::mat4* projectionMatrix, Camera* camera, Light* light);
	void render();

	void translate(glm::vec3 translation);
	void rotate(float radians, glm::vec3 axis);
};

class LightingTest {
private:
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	Camera camera;
	Light light;

	CubePhong* cube;
public:
	void initialize(GLuint* shaderProgramHandleArray);
	void update(Input* input, float elapsedTimeS);
	void render();

	void quit();
};