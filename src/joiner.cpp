#include "joiner.h"

void Joiner::initialize(GLuint *shaderProgramHandle) {
    rectangle = new RectangleBasic();
    rectangle->initialize(shaderProgramHandle);
}

void Joiner::update() {

}

void Joiner::render() {
    rectangle->render();
}