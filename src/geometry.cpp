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

	resolutionLocationHandle = glGetUniformLocation(*shaderProgramHandle, "resolution");
    colorLocationHandle = glGetUniformLocation(*shaderProgramHandle, "color");
}

void RectangleBasic::render() {
	glUseProgram(*shaderProgramHandle);
	glBindVertexArray(vaoHandle);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), getPositionVertexData(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	glUniform2fv(resolutionLocationHandle, 1, glm::value_ptr(resolution));
	glUniform4fv(colorLocationHandle, 1, glm::value_ptr(color));

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

void RectangleTextured::initialize(GLuint* shaderProgramHandle, GLuint* textureHandle, Vector2 position, int width, int height) {
	this->shaderProgramHandle = shaderProgramHandle;
	this->textureHandle = textureHandle;
	
	this->position = position;
	this->width = width;
	this->height = height;

    glGenVertexArrays(1, &vaoHandle);
   	glGenBuffers(2, vboHandles);

    positionBufferHandle = vboHandles[0];
    textureBufferHandle = vboHandles[1];

	resolutionLocationHandle = glGetUniformLocation(*shaderProgramHandle, "resolution");
	textureSamplerLocationHandle = glGetUniformLocation(*shaderProgramHandle, "textureSampler");
}

void RectangleTextured::render() {
	glUseProgram(*shaderProgramHandle);
	glBindVertexArray(vaoHandle);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), getPositionVertexData(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, textureBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), getTextureVertexData(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	glUniform2fv(resolutionLocationHandle, 1, glm::value_ptr(resolution));

	glBindTexture(GL_TEXTURE_2D, *textureHandle);
	glUniform1i(textureSamplerLocationHandle, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

float* RectangleTextured::getPositionVertexData() {
	static float vertexData[12];
	vertexData[0] = position.x; 			vertexData[1] = position.y;
	vertexData[2] = position.x + width; 	vertexData[3] = position.y;
	vertexData[4] = position.x;				vertexData[5] = position.y + height;
	vertexData[6] = position.x;				vertexData[7] = position.y + height;
	vertexData[8] = position.x + width; 	vertexData[9] = position.y;
	vertexData[10] = position.x + width; 	vertexData[11] = position.y + height;

	return vertexData;
}

float* RectangleTextured::getTextureVertexData() {
	static float vertexData[12];
	vertexData[0] = 0; 		vertexData[1] = 0;
	vertexData[2] = 1; 		vertexData[3] = 0;
	vertexData[4] = 0;		vertexData[5] = 1;
	vertexData[6] = 0;		vertexData[7] = 1;
	vertexData[8] = 1; 		vertexData[9] = 0;
	vertexData[10] = 1; 	vertexData[11] = 1;

	return vertexData;
}