#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Joiner {
private:
	GLuint vaoHandle;
	GLuint vboHandles[1];
	GLuint positionBufferHandle;
public:
	void initialize();
	void update();
	void render(GLuint &shaderProgramHandle);
};