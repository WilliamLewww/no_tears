#pragma once
#include "../geometry.h"
#include "../input.h"

class RectangleAvoid {
private:
	int width, height;

	glm::vec4 color;

	GLuint vaoHandle;
	GLuint vboHandles[1];
	GLuint positionBufferHandle;

	GLuint resolutionLocationHandle;
	GLuint colorLocationHandle;
	GLuint mousePositionLocationHandle;
	GLuint effectScaleLocationHandle;

	GLuint shaderProgramHandle;

	float* getPositionVertexData();
public:
	Vector2 position;

	inline void setColor(int r, int g, int b, int a) {
		color = glm::vec4(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}

	void initialize(GLuint shaderProgramHandle, Vector2 position, int width, int height);
	void render(float mousePositionX, float mousePositionY, float effectScale);
};

class ScavengerHunt {
private:
	Vector2 mousePosition;
	float effectScale;

	RectangleAvoid* rectangleList;
	int rectangleCount;
	
	int rectangleSize;
public:
	void initialize(GLuint* shaderProgramHandleArray);
	void update(Input* input, float elapsedTimeS);
	void render();

	void quit();
};