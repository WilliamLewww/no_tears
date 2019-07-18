#include "lighting_test.h"

void LightingTest::initialize(GLuint* shaderProgramHandleArray) {
	camera.position = glm::vec3(0.0f, -5.0f, 8.0f);
	camera.up = glm::vec3(0.0f, 1.0f, 0.0f);

	camera.pitch = 0.0f;
	camera.yaw = -90.0f;
	camera.front.x = cos(glm::radians(camera.pitch)) * cos(glm::radians(camera.yaw));
	camera.front.y = sin(glm::radians(camera.pitch));
	camera.front.z = cos(glm::radians(camera.pitch)) * sin(glm::radians(camera.yaw));
	camera.front = glm::normalize(camera.front);

	viewMatrix = glm::lookAt(camera.position, camera.position + camera.front, camera.up);

	projectionMatrix = glm::perspective(glm::radians(45.0f), 1920.0f / 1080.0f, 0.1f, 100.0f);

	light.position = glm::vec3(0.0f, 2.5f, 0.0f);
	light.color = glm::vec3(1.0f, 1.0f, 1.0f);

	cubeCount = 285;
	cubeList = new CubePhong[cubeCount];

	int index = 0;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < x; y++) {
			for (int z = 0; z < x; z++) {
				cubeList[index].initialize(shaderProgramHandleArray[3], &viewMatrix, &projectionMatrix, &camera, &light);
				cubeList[index].setColor(rand() % 256, rand() % 256, rand() % 256, 255.0);
				cubeList[index].translate(glm::vec3(y, -x, z));
				index += 1;
			}
		}
	}
}

float previousMouseX = -1.0f, previousMouseY = -1.0f;
float currentLightRotation = 0.0f;
void LightingTest::update(Input* input, float elapsedTimeS) {
	currentLightRotation += 0.001f;

	light.position.x = 25.0f * sin(currentLightRotation);
	light.position.z = 25.0f * cos(currentLightRotation);
	
	if (input->checkKeyDown(265)) { camera.position += 0.05f * camera.front; }
	if (input->checkKeyDown(264)) { camera.position -= 0.05f * camera.front; }
	if (input->checkKeyDown(263)) { camera.position -= glm::normalize(glm::cross(camera.front, camera.up)) * 0.05f; }
	if (input->checkKeyDown(262)) { camera.position += glm::normalize(glm::cross(camera.front, camera.up)) * 0.05f; }

	Vector2 mousePosition = input->getMousePosition();
	if (previousMouseX == -1.0f) { previousMouseX = mousePosition.x; }
	if (previousMouseY == -1.0f) { previousMouseY = mousePosition.y; }

	float xoffset = mousePosition.x - previousMouseX;
	float yoffset = previousMouseY - mousePosition.y;
	previousMouseX = mousePosition.x;
	previousMouseY = mousePosition.y;

	float sensitivity = 0.05f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	camera.yaw += xoffset;
	camera.pitch += yoffset;
	camera.front.x = cos(glm::radians(camera.pitch)) * cos(glm::radians(camera.yaw));
	camera.front.y = sin(glm::radians(camera.pitch));
	camera.front.z = cos(glm::radians(camera.pitch)) * sin(glm::radians(camera.yaw));
	camera.front = glm::normalize(camera.front);

	viewMatrix = glm::lookAt(camera.position, camera.position + camera.front, camera.up);
}

void LightingTest::render() {
	for (int x = 0; x < cubeCount; x++) {
		cubeList[x].render();
	}
}

void LightingTest::quit() {
	delete [] cubeList;
}

void CubePhong::initialize(GLuint shaderProgramHandle, glm::mat4* viewMatrix, glm::mat4* projectionMatrix, Camera* camera, Light* light) {
	positionVertexData = new float[108]{
	    -0.5f, -0.5f, -0.5f,
	     0.5f, -0.5f, -0.5f, 
	     0.5f,  0.5f, -0.5f, 
	     0.5f,  0.5f, -0.5f, 
	    -0.5f,  0.5f, -0.5f, 
	    -0.5f, -0.5f, -0.5f, 

	    -0.5f, -0.5f,  0.5f,
	     0.5f, -0.5f,  0.5f,
	     0.5f,  0.5f,  0.5f,
	     0.5f,  0.5f,  0.5f,
	    -0.5f,  0.5f,  0.5f,
	    -0.5f, -0.5f,  0.5f,

	    -0.5f,  0.5f,  0.5f,
	    -0.5f,  0.5f, -0.5f,
	    -0.5f, -0.5f, -0.5f,
	    -0.5f, -0.5f, -0.5f,
	    -0.5f, -0.5f,  0.5f,
	    -0.5f,  0.5f,  0.5f,

	     0.5f,  0.5f,  0.5f,
	     0.5f,  0.5f, -0.5f,
	     0.5f, -0.5f, -0.5f,
	     0.5f, -0.5f, -0.5f,
	     0.5f, -0.5f,  0.5f,
	     0.5f,  0.5f,  0.5f,

	    -0.5f, -0.5f, -0.5f,
	     0.5f, -0.5f, -0.5f,
	     0.5f, -0.5f,  0.5f,
	     0.5f, -0.5f,  0.5f,
	    -0.5f, -0.5f,  0.5f,
	    -0.5f, -0.5f, -0.5f,

	    -0.5f,  0.5f, -0.5f,
	     0.5f,  0.5f, -0.5f,
	     0.5f,  0.5f,  0.5f,
	     0.5f,  0.5f,  0.5f,
	    -0.5f,  0.5f,  0.5f,
	    -0.5f,  0.5f, -0.5f
	};

	normalVertexData = new float[108]{
	    0.0f,  0.0f, -1.0f,
	    0.0f,  0.0f, -1.0f, 
	    0.0f,  0.0f, -1.0f, 
	    0.0f,  0.0f, -1.0f, 
	    0.0f,  0.0f, -1.0f, 
	    0.0f,  0.0f, -1.0f, 

	    0.0f,  0.0f, 1.0f,
	    0.0f,  0.0f, 1.0f,
	    0.0f,  0.0f, 1.0f,
	    0.0f,  0.0f, 1.0f,
	    0.0f,  0.0f, 1.0f,
	    0.0f,  0.0f, 1.0f,

	    -1.0f,  0.0f,  0.0f,
	    -1.0f,  0.0f,  0.0f,
	    -1.0f,  0.0f,  0.0f,
	    -1.0f,  0.0f,  0.0f,
	    -1.0f,  0.0f,  0.0f,
	    -1.0f,  0.0f,  0.0f,

	    1.0f,  0.0f,  0.0f,
	    1.0f,  0.0f,  0.0f,
	    1.0f,  0.0f,  0.0f,
	    1.0f,  0.0f,  0.0f,
	    1.0f,  0.0f,  0.0f,
	    1.0f,  0.0f,  0.0f,

	    0.0f, -1.0f,  0.0f,
	    0.0f, -1.0f,  0.0f,
	    0.0f, -1.0f,  0.0f,
	    0.0f, -1.0f,  0.0f,
	    0.0f, -1.0f,  0.0f,
	    0.0f, -1.0f,  0.0f,

	    0.0f,  1.0f,  0.0f,
	    0.0f,  1.0f,  0.0f,
	    0.0f,  1.0f,  0.0f,
	    0.0f,  1.0f,  0.0f,
	    0.0f,  1.0f,  0.0f,
	    0.0f,  1.0f,  0.0f
	};

	color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	modelMatrix = glm::mat4(1.0f);

	this->shaderProgramHandle = shaderProgramHandle;
	this->viewMatrix = viewMatrix;
	this->projectionMatrix = projectionMatrix;

	this->camera = camera;
	this->light = light;

	glGenVertexArrays(1, &vaoHandle);
	glGenBuffers(2, vboHandles);

	positionBufferHandle = vboHandles[0];
	normalBufferHandle = vboHandles[1];

	modelMatrixLocationHandle = glGetUniformLocation(shaderProgramHandle, "modelMatrix");
	viewMatrixLocationHandle = glGetUniformLocation(shaderProgramHandle, "viewMatrix");
	projectionMatrixLocationHandle = glGetUniformLocation(shaderProgramHandle, "projectionMatrix");

	colorLocationHandle = glGetUniformLocation(shaderProgramHandle, "color");

	lightPositionLocationHandle = glGetUniformLocation(shaderProgramHandle, "lightPosition");
	lightColorLocationHandle = glGetUniformLocation(shaderProgramHandle, "lightColor");
	
	viewPositionLocationHandle = glGetUniformLocation(shaderProgramHandle, "viewPosition");
}

void CubePhong::render() {
	glEnable(GL_DEPTH_TEST);
	glUseProgram(shaderProgramHandle);
	glBindVertexArray(vaoHandle);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), positionVertexData, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, normalBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), normalVertexData, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glUniformMatrix4fv(modelMatrixLocationHandle, 1, GL_FALSE, glm::value_ptr(modelMatrix));
	glUniformMatrix4fv(viewMatrixLocationHandle, 1, GL_FALSE, glm::value_ptr(*viewMatrix));
	glUniformMatrix4fv(projectionMatrixLocationHandle, 1, GL_FALSE, glm::value_ptr(*projectionMatrix));

	glUniform4fv(colorLocationHandle, 1, glm::value_ptr(color));

	glUniform3fv(lightPositionLocationHandle, 1, glm::value_ptr(light->position));
	glUniform3fv(lightColorLocationHandle, 1, glm::value_ptr(light->color));
	
	glUniform3fv(viewPositionLocationHandle, 1, glm::value_ptr(camera->position));

	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void CubePhong::translate(glm::vec3 translation) {
	modelMatrix = glm::translate(modelMatrix, translation);
}

void CubePhong::rotate(float radians, glm::vec3 axis) {
	modelMatrix = glm::rotate(modelMatrix, radians, axis);
}