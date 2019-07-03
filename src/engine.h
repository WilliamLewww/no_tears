#define GLFW_EXPOSE_NATIVE_WIN32

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "external_context.h"
#include "geometry.h"
#include "joiner.h"

class Engine {
private:
	Geometry* geometry;
	Joiner* joiner;
	
	const GLFWvidmode* mode;
	GLFWwindow* window;
	HWND windowNative;
	LONG windowLong;

	std::vector<GLuint> shaderProgramList;

	void update();
	void render();

	void initializeContextGL();
	void initializeWindow();
	void initializeShaderPrograms();

	std::string readShaderSource(const char* filepath);
	GLuint createShaderProgram(std::string vertexShader, std::string fragmentShader);
public:
	void initialize();
	void start();
	void quit();
};