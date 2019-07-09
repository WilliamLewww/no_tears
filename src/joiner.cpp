#include "joiner.h"

void Joiner::initialize(GLuint* shaderProgramHandleArray, GLuint* textureHandleArray) {
	if (currentExample == EXAMPLE_FLAG::NO_TEARS) {
		noTears = new NoTears;
		noTears->initialize(shaderProgramHandleArray, textureHandleArray);
	}

	if (currentExample == EXAMPLE_FLAG::SCAVENGER_HUNT) {
		scavengerHunt = new ScavengerHunt;
		scavengerHunt->initialize(shaderProgramHandleArray);
	}
}

void Joiner::update(Input* input, float elapsedTimeS) {
	if (currentExample == EXAMPLE_FLAG::NO_TEARS) { noTears->update(elapsedTimeS); }
	if (currentExample == EXAMPLE_FLAG::SCAVENGER_HUNT) { scavengerHunt->update(input, elapsedTimeS); }
}

void Joiner::render() {
	if (currentExample == EXAMPLE_FLAG::NO_TEARS) { noTears->render(); }
	if (currentExample == EXAMPLE_FLAG::SCAVENGER_HUNT) { scavengerHunt->render(); }
}

void Joiner::quit() {
	if (currentExample == EXAMPLE_FLAG::NO_TEARS) { 
		noTears->quit();
		delete noTears;
	}

	if (currentExample == EXAMPLE_FLAG::SCAVENGER_HUNT) {
		scavengerHunt->quit();
		delete scavengerHunt;
	}
}