#include "joiner.h"
#include <stdlib.h>

const int rectangleCount = 250;
float velocityXList[rectangleCount];
float velocityYList[rectangleCount];

void Joiner::initialize(GLuint* shaderProgramHandle) {
    rectangleList = new RectangleBasic[rectangleCount];
    for (int x = 0; x < rectangleCount; x++) {
    	rectangleList[x].initialize(shaderProgramHandle, {(float)(rand() % 1871), (float)(rand() % 1031)}, 50, 50);
    	rectangleList[x].setColor(rand() % 256, rand() % 256, rand() % 256, (rand() % 2 == 0) ? 50 : 255);
    	
    	if (rand() % 2 == 0) { velocityXList[x] = -(((rand() % 11) / 10.0f) + 0.01); }
    	else { velocityXList[x] = (((rand() % 11) / 10.0f) + 0.01); }

    	if (rand() % 2 == 0) { velocityYList[x] = -(((rand() % 11) / 10.0f) + 0.01); }
    	else { velocityYList[x] = (((rand() % 11) / 10.0f) + 0.01); }
    }
}

void Joiner::update(float elapsedTimeS) {
	for (int x = 0; x < rectangleCount; x++) {
		rectangleList[x].position.x += velocityXList[x];
		rectangleList[x].position.y += velocityYList[x];

		if (rectangleList[x].position.x <= 0 || rectangleList[x].position.x + 50 >= screenWidth) {
			velocityXList[x] = -velocityXList[x];
		}
		if (rectangleList[x].position.y <= 0 || rectangleList[x].position.y + 50 >= screenHeight) {
			velocityYList[x] = -velocityYList[x];
		}
	}
}

void Joiner::render() {
	for (int x = 0; x < rectangleCount; x++) {
    	rectangleList[x].render();
	}
}