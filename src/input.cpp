#include "input.h"

void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		
	}

	if (action == GLFW_RELEASE) {

	}
}

void Input::cursorPositionCallback(GLFWwindow* window, double x, double y) {

}

Vector2 Input::getMousePosition() {
	Vector2 tempPosition = { (float)mousePositionX, (float)mousePositionY };
	return tempPosition;
}

void Input::update(GLFWwindow* window) {
    glfwGetCursorPos(window, &mousePositionX, &mousePositionY);
}