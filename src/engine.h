#define GLFW_EXPOSE_NATIVE_WIN32

#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "external_context.h"
#include "joiner.h"

class Engine {
private:
	Joiner joiner;
	
	const GLFWvidmode* mode;
	GLFWwindow* window;
	HWND windowNative;
	LONG windowLong;

	void update();
	void render();

	void initializeContextGL();
	void initializeWindow();
public:
	void initialize();
	void start();
	void quit();
};