#include "geometry.h"

float positionData[] = {
    0.0f,  0.0f,
    50.0f, 0.0f,
    0.0f,  50.0f
};

void RectangleBasic::initialize(GLuint* shaderProgramHandle) {
	this->shaderProgramHandle = shaderProgramHandle;

   	glGenBuffers(1, vboHandles);
    positionBufferHandle = vboHandles[0];
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positionData, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
}

void RectangleBasic::render() {
	glUseProgram(*shaderProgramHandle);

	colorLocationHandle = glGetUniformLocation(*shaderProgramHandle, "color");
	resolutionLocationHandle = glGetUniformLocation(*shaderProgramHandle, "resolution");

	glUniform4fv(colorLocationHandle, 1, glm::value_ptr(color));
	glUniform2fv(resolutionLocationHandle, 1, glm::value_ptr(resolution));

    glBindVertexArray(vaoHandle);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}