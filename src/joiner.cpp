#include "joiner.h"
#include <stdlib.h>

const int rectangleCount = 50;
float velocityXList[rectangleCount];
float velocityYList[rectangleCount];

int sizeList[rectangleCount];

void Joiner::initialize(GLuint* shaderProgramHandleArray, GLuint* textureHandleArray) {
	rectangleList = new RectangleTextured[rectangleCount];
    for (int x = 0; x < rectangleCount; x++) {
    	sizeList[x] = rand() % (200 - 50 + 1) + 50;
    	rectangleList[x].initialize(shaderProgramHandleArray[1], textureHandleArray[0], {(float)(rand() % (1920 - sizeList[x])), (float)(rand() % (1080 - sizeList[x]))}, sizeList[x], sizeList[x]);
    	
    	if (rand() % 2 == 0) { velocityXList[x] = -(((rand() % 11) / 10.0f) + 0.1f); }
    	else { velocityXList[x] = (((rand() % 11) / 10.0f) + 0.1f); }

    	if (rand() % 2 == 0) { velocityYList[x] = -(((rand() % 11) / 10.0f) + 0.1f); }
    	else { velocityYList[x] = (((rand() % 11) / 10.0f) + 0.1f); }
	}
}

void Joiner::update(float elapsedTimeS) {
	for (int x = 0; x < rectangleCount; x++) {
		rectangleList[x].position.x += velocityXList[x];
		rectangleList[x].position.y += velocityYList[x];

		if (rectangleList[x].position.x <= 0 || rectangleList[x].position.x + sizeList[x] >= screenWidth) {
			velocityXList[x] = -velocityXList[x];
		}
		if (rectangleList[x].position.y <= 0 || rectangleList[x].position.y + sizeList[x] >= screenHeight) {
			velocityYList[x] = -velocityYList[x];
		}
	}
}

void Joiner::render() {
	for (int x = 0; x < rectangleCount; x++) {
    	rectangleList[x].render();
	}
}

void Joiner::quit() {
	delete [] rectangleList;
}