#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "vector2.h"

class Input {
private:
	double mousePositionX, mousePositionY;
public:
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursorPositionCallback(GLFWwindow* window, double x, double y);
	
	Vector2 getMousePosition();

	void update(GLFWwindow* window);
};