#define GLFW_EXPOSE_NATIVE_WIN32

#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <SOIL.h>
#include "external_context.h"
#include "input.h"
#include "joiner.h"

class Engine {
private:
	Input* input;
	Joiner* joiner;

	const GLFWvidmode* mode;
	GLFWwindow* window;
	HWND windowNative;
	LONG windowLong;

	GLuint* shaderProgramHandleArray;
	GLuint* textureHandleArray;

	void initializeContextGL();
	void initializeWindow();
	void initializeShaders();
	void initializeTextures();

	void update(float elapsedTimeS);
	void render();

	std::string readShaderSource(const char* filepath);
	GLuint createShaderProgram(std::string vertexShaderString, std::string fragmentShaderString);
public:
	void initialize();
	void start();
	void quit();
};