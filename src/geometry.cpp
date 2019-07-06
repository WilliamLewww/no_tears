#include "geometry.h"

void RectangleBasic::initialize(GLuint* shaderProgramHandle, Vector2 position, int width, int height) {
	this->shaderProgramHandle = shaderProgramHandle;
	this->position = position;
	this->width = width;
	this->height = height;

    color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);
    glEnableVertexAttribArray(0);

   	glGenBuffers(1, vboHandles);
    positionBufferHandle = vboHandles[0];

    colorLocationHandle = glGetUniformLocation(*shaderProgramHandle, "color");
	resolutionLocationHandle = glGetUniformLocation(*shaderProgramHandle, "resolution");

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
}

void RectangleBasic::render() {
	glUseProgram(*shaderProgramHandle);

	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), getPositionVertexData(), GL_STATIC_DRAW);

	glUniform4fv(colorLocationHandle, 1, glm::value_ptr(color));
	glUniform2fv(resolutionLocationHandle, 1, glm::value_ptr(resolution));

    glBindVertexArray(vaoHandle);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

float* RectangleBasic::getPositionVertexData() {
	static float vertexData[12] = {
		position.x, position.y,
		position.x + width, position.y,
		position.x, position.y + height,
		position.x, position.y + height,
		position.x + width, position.y,
		position.x + width, position.y + height,
	};

	return vertexData;
}