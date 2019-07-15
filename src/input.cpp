#include "input.h"

std::vector<int> Input::keyDownList;

void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		keyDownList.push_back(key);
	}

	if (action == GLFW_RELEASE) {
		for (int x = 0; x < keyDownList.size(); x++) {
			if (key == keyDownList[x]) {
				keyDownList.erase(keyDownList.begin() + x);
			}
		}
	}
}

void Input::cursorPositionCallback(GLFWwindow* window, double x, double y) {

}

bool Input::checkKeyDown(int key) {
	for (int x = 0; x < keyDownList.size(); x++) {
		if (key == keyDownList[x]) {
			return true;
		}
	}

	return false;
}

Vector2 Input::getMousePosition() {
	Vector2 tempPosition = { (float)mousePositionX, (float)mousePositionY };
	return tempPosition;
}

void Input::update(GLFWwindow* window) {
    glfwGetCursorPos(window, &mousePositionX, &mousePositionY);
}