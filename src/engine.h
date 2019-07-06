#define GLFW_EXPOSE_NATIVE_WIN32

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "external_context.h"
#include "joiner.h"

class Engine {
private:
	Joiner* joiner;

	const GLFWvidmode* mode;
	GLFWwindow* window;
	HWND windowNative;
	LONG windowLong;

	GLuint shaderProgramHandle;

	void initializeContextGL();
	void initializeWindow();

	void update();
	void render();

	std::string readShaderSource(const char* filepath);
	GLuint createShaderProgram(std::string vertexShaderString, std::string fragmentShaderString);
public:
	void initialize();
	void start();
	void quit();
};