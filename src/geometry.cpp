#include "geometry.h"

void RectangleBasic::initialize(GLuint* shaderProgramHandle, Vector2 position, int width, int height) {
	this->shaderProgramHandle = shaderProgramHandle;
	this->position = position;
	this->width = width;
	this->height = height;

    color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

    glGenVertexArrays(1, &vaoHandle);
   	glGenBuffers(1, vboHandles);

    positionBufferHandle = vboHandles[0];
    colorLocationHandle = glGetUniformLocation(*shaderProgramHandle, "color");
	resolutionLocationHandle = glGetUniformLocation(*shaderProgramHandle, "resolution");
}

void RectangleBasic::render() {
	glUseProgram(*shaderProgramHandle);
	glBindVertexArray(vaoHandle);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), getPositionVertexData(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	glUniform4fv(colorLocationHandle, 1, glm::value_ptr(color));
	glUniform2fv(resolutionLocationHandle, 1, glm::value_ptr(resolution));

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

float* RectangleBasic::getPositionVertexData() {
	static float vertexData[12];
	vertexData[0] = position.x; 			vertexData[1] = position.y;
	vertexData[2] = position.x + width; 	vertexData[3] = position.y;
	vertexData[4] = position.x;				vertexData[5] = position.y + height;
	vertexData[6] = position.x;				vertexData[7] = position.y + height;
	vertexData[8] = position.x + width; 	vertexData[9] = position.y;
	vertexData[10] = position.x + width; 	vertexData[11] = position.y + height;

	return vertexData;
}