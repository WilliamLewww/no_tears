#include "engine.h"

void Engine::initialize() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	glfwWindowHint(GLFW_FOCUSED, GLFW_FALSE);
	glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_FALSE);

	mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	window = glfwCreateWindow(mode->width, mode->height, "NoTears", NULL, NULL);
	windowNative = glfwGetWin32Window(window);
	glfwSetWindowPos(window, 0, 0);
	glfwMakeContextCurrent(window);

	windowLong = GetWindowLong(windowNative, GWL_EXSTYLE);
	SetWindowLong(windowNative, GWL_EXSTYLE, windowLong | WS_EX_TRANSPARENT | WS_EX_LAYERED);

	EnumWindows(MatchTargetWindow, 0);
	
	glewInit();
}

void Engine::start() {
	while (!glfwWindowShouldClose(window)) {
		update();
		render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Engine::quit() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Engine::update() {

}

void Engine::render() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}