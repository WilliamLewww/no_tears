#include "scavenger_hunt.h"

void ScavengerHunt::initialize(GLuint* shaderProgramHandleArray) {
	effectScale = 25.0;

	rectangleCount = 5000;
	rectangleSize = 25;

	rectangleList = new RectangleAvoid[rectangleCount];
	for (int x = 0; x < rectangleCount; x++) {
		float xPos = (rand() % (screenWidth + rectangleSize + rectangleSize + 1) - rectangleSize);
		float yPos = (rand() % (screenWidth + rectangleSize + rectangleSize + 1) - rectangleSize);
		rectangleList[x].initialize(shaderProgramHandleArray[2], {xPos, yPos}, rectangleSize, rectangleSize);
		rectangleList[x].setColor(rand() % 256, rand() % 256, rand() % 256,255);
	}
}

void ScavengerHunt::update(Input* input, float elapsedTimeS) {
	mousePosition = input->getMousePosition();

	if (input->checkKeyDown(264)) { effectScale -= 1.0; }
	if (input->checkKeyDown(265)) { effectScale += 1.0; }
}

void ScavengerHunt::render() {
	for (int x = 0; x < rectangleCount; x++) {
		rectangleList[x].render(mousePosition.x, mousePosition.y, effectScale);
	}
}

void ScavengerHunt::quit() {
	delete [] rectangleList;
}

void RectangleAvoid::initialize(GLuint shaderProgramHandle, Vector2 position, int width, int height) {
	this->shaderProgramHandle = shaderProgramHandle;
	this->position = position;
	this->width = width;
	this->height = height;

    color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

    glGenVertexArrays(1, &vaoHandle);
   	glGenBuffers(1, vboHandles);

    positionBufferHandle = vboHandles[0];

	resolutionLocationHandle = glGetUniformLocation(shaderProgramHandle, "resolution");
    colorLocationHandle = glGetUniformLocation(shaderProgramHandle, "color");
    mousePositionLocationHandle = glGetUniformLocation(shaderProgramHandle, "mousePosition");
    effectScaleLocationHandle = glGetUniformLocation(shaderProgramHandle, "effectScale");
}

void RectangleAvoid::render(float mousePositionX, float mousePositionY, float effectScale) {
	glUseProgram(shaderProgramHandle);
	glBindVertexArray(vaoHandle);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), getPositionVertexData(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	glUniform2fv(resolutionLocationHandle, 1, glm::value_ptr(resolution));
	glUniform4fv(colorLocationHandle, 1, glm::value_ptr(color));

	glUniform2f(mousePositionLocationHandle, mousePositionX, mousePositionY);
	glUniform1f(effectScaleLocationHandle, effectScale);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

float* RectangleAvoid::getPositionVertexData() {
	static float vertexData[12];
	vertexData[0] = position.x; 			vertexData[1] = position.y;
	vertexData[2] = position.x + width; 	vertexData[3] = position.y;
	vertexData[4] = position.x;				vertexData[5] = position.y + height;
	vertexData[6] = position.x;				vertexData[7] = position.y + height;
	vertexData[8] = position.x + width; 	vertexData[9] = position.y;
	vertexData[10] = position.x + width; 	vertexData[11] = position.y + height;

	return vertexData;
}