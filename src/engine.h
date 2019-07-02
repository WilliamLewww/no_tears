#define GLFW_EXPOSE_NATIVE_WIN32

#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "external.h"

class Engine {
private:
	const GLFWvidmode* mode;
	GLFWwindow* window;
	HWND windowNative;
	LONG windowLong;

	void update();
	void render();
public:
	void initialize();
	void start();
	void quit();
};