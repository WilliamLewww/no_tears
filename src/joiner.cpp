#include "joiner.h"
#include <stdlib.h>

void Joiner::initialize(GLuint* shaderProgramHandleArray, GLuint* textureHandleArray) {
	rectangle = new RectangleTextured;
	rectangle->initialize(shaderProgramHandleArray[1], textureHandleArray[0], {50, 50}, 400, 400);
}

void Joiner::update(float elapsedTimeS) {

}

void Joiner::render() {
	rectangle->render();
}

void Joiner::quit() {

}