#include "lighting_test.h"

void LightingTest::initialize(GLuint* shaderProgramHandleArray) {
	cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	cameraPitch = 0.0f;
	cameraYaw = -90.0f;
	cameraFront.x = cos(glm::radians(cameraPitch)) * cos(glm::radians(cameraYaw));
	cameraFront.y = sin(glm::radians(cameraPitch));
	cameraFront.z = cos(glm::radians(cameraPitch)) * sin(glm::radians(cameraYaw));
	cameraFront = glm::normalize(cameraFront);

	viewMatrix = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);

	projectionMatrix = glm::perspective(glm::radians(45.0f), 1920.0f / 1080.0f, 0.1f, 100.0f);

	cube = new CubePhong;
	cube->initialize(shaderProgramHandleArray[3], &viewMatrix, &projectionMatrix);
}

void LightingTest::update(Input* input, float elapsedTimeS) {
	if (input->checkKeyDown(265)) {
		cameraPosition += 0.05f * cameraFront;
	}
	if (input->checkKeyDown(264)) {
		cameraPosition -= 0.05f * cameraFront;
	}
	if (input->checkKeyDown(263)) {
		cameraYaw -= 0.3f;
		cameraFront.x = cos(glm::radians(cameraPitch)) * cos(glm::radians(cameraYaw));
		cameraFront.y = sin(glm::radians(cameraPitch));
		cameraFront.z = cos(glm::radians(cameraPitch)) * sin(glm::radians(cameraYaw));
		cameraFront = glm::normalize(cameraFront);
	}
	if (input->checkKeyDown(262)) {
		cameraYaw += 0.3f;
		cameraFront.x = cos(glm::radians(cameraPitch)) * cos(glm::radians(cameraYaw));
		cameraFront.y = sin(glm::radians(cameraPitch));
		cameraFront.z = cos(glm::radians(cameraPitch)) * sin(glm::radians(cameraYaw));
		cameraFront = glm::normalize(cameraFront);
	}

	viewMatrix = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}

void LightingTest::render() {
	cube->render();
}

void LightingTest::quit() {
	delete cube;
}

void CubePhong::initialize(GLuint shaderProgramHandle, glm::mat4* viewMatrix, glm::mat4* projectionMatrix) {
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

	modelMatrix = glm::mat4(1.0f);

	this->shaderProgramHandle = shaderProgramHandle;
	this->viewMatrix = viewMatrix;
	this->projectionMatrix = projectionMatrix;

	glGenVertexArrays(1, &vaoHandle);
	glGenBuffers(2, vboHandles);

	positionBufferHandle = vboHandles[0];
	normalBufferHandle = vboHandles[1];

	modelMatrixLocationHandle = glGetUniformLocation(shaderProgramHandle, "modelMatrix");
	viewMatrixLocationHandle = glGetUniformLocation(shaderProgramHandle, "viewMatrix");
	projectionMatrixLocationHandle = glGetUniformLocation(shaderProgramHandle, "projectionMatrix");
}

void CubePhong::render() {
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

	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void CubePhong::translate(glm::vec3 translation) {
	modelMatrix = glm::translate(modelMatrix, translation);
}

void CubePhong::rotate(float radians, glm::vec3 axis) {
	modelMatrix = glm::rotate(modelMatrix, radians, axis);
}