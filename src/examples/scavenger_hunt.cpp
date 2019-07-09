#include "scavenger_hunt.h"

void ScavengerHunt::initialize(GLuint* shaderProgramHandleArray) {
	rectangleCount = 8000;
	rectangleSize = 50;

	rectangleList = new RectangleBasic[rectangleCount];
	for (int x = 0; x < rectangleCount; x++) {
		float xPos = (rand() % (screenWidth + rectangleSize + rectangleSize + 1) - rectangleSize);
		float yPos = (rand() % (screenWidth + rectangleSize + rectangleSize + 1) - rectangleSize);
		rectangleList[x].initialize(shaderProgramHandleArray[0], {xPos, yPos}, rectangleSize, rectangleSize);
		rectangleList[x].setColor(rand() % 256, rand() % 256, rand() % 256,255);
	}
}

void ScavengerHunt::update(Input* input, float elapsedTimeS) {

}

void ScavengerHunt::render() {
	for (int x = 0; x < rectangleCount; x++) {
		rectangleList[x].render();
	}
}

void ScavengerHunt::quit() {
	delete [] rectangleList;
}