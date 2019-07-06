#include "engine.h"

void Engine::initialize() {
	initializeContextGL();
	initializeWindow();
    glewInit();

    EnumWindows(MatchTargetWindow, 0);
    setupResoultion(mode->width, mode->height);

    std::string vertexShaderString = readShaderSource("shaders/basic.vertex");
    std::string fragmentShaderString = readShaderSource("shaders/basic.fragment");
    shaderProgramHandle = createShaderProgram(vertexShaderString, fragmentShaderString);

    joiner = new Joiner();
    joiner->initialize(&shaderProgramHandle);
}

void Engine::initializeContextGL() { 
	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

void Engine::initializeWindow() {
    mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    window = glfwCreateWindow(mode->width, mode->height, "NoTears", NULL, NULL);
    windowNative = glfwGetWin32Window(window);
    glfwSetWindowPos(window, 0, 0);
    glfwMakeContextCurrent(window);

    windowLong = GetWindowLong(windowNative, GWL_EXSTYLE);
    SetWindowLong(windowNative, GWL_EXSTYLE, windowLong | WS_EX_TRANSPARENT | WS_EX_LAYERED);
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
	joiner->update();
}

void Engine::render() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   	joiner->render();
}

std::string Engine::readShaderSource(const char* filepath) {
    std::string content;
    std::ifstream fileStream(filepath, std::ios::in);
    std::string line = "";

    while (!fileStream.eof()) {
        getline(fileStream, line);
        content.append(line + "\n");
    }
    fileStream.close();

    return content;
}

GLuint Engine::createShaderProgram(std::string vertexShaderString, std::string fragmentShaderString) {
    const char* vertexShaderSource = vertexShaderString.c_str();
    const char* fragmentShaderSource = fragmentShaderString.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    return shaderProgram;
}