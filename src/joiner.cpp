#include "joiner.h"

void Joiner::initialize(GLuint* shaderProgramHandle) {
    rectangle = new RectangleBasic();
    rectangle->initialize(shaderProgramHandle, {0,0}, 50, 50);
}

void Joiner::update() {

}

void Joiner::render() {
    rectangle->render();
}