#include "joiner.h"

float positionData[] = {
    -0.8f, -0.8f,
     0.8f, -0.8f,
     0.0f,  0.8f
};

void Joiner::initialize() {
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

void Joiner::update() {

}

void Joiner::render(GLuint &shaderProgramHandle) {
	glUseProgram(shaderProgramHandle);

	colorLocationHandle = glGetUniformLocation(shaderProgramHandle, "color");
	glUniform4fv(colorLocationHandle, 1, glm::value_ptr(color));

    glBindVertexArray(vaoHandle);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}