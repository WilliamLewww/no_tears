#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Joiner {
private:
	GLuint vaoHandle;
	GLuint vboHandles[1];
	GLuint positionBufferHandle;
	GLuint colorLocationHandle;

	glm::vec4 color;
public:
	void initialize();
	void update();
	void render(GLuint &shaderProgramHandle);
};