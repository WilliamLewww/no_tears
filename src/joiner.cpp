#include "joiner.h"

void Joiner::initialize(GLuint* shaderProgramHandleArray, GLuint* textureHandleArray) {
	noTears = new NoTears;
	noTears->initialize(shaderProgramHandleArray, textureHandleArray);
}

void Joiner::update(float elapsedTimeS) {
	noTears->update(elapsedTimeS);
}

void Joiner::render() {
	noTears->render();
}

void Joiner::quit() {
	noTears->quit();
	delete noTears;
}