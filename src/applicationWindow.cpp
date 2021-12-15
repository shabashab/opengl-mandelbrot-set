#include <GL/glew.h>
#include <iostream>

#include "applicationWindow.hpp"
#include "shaderProgramBuilder.hpp"

ApplicationWindow::ApplicationWindow() : Window(1000, 1000, "My application")
{
	glfwSetWindowSizeCallback(this->glfwWindow, [](GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	});
}

void ApplicationWindow::loop()
{
	int upKeyState = glfwGetKey(this->glfwWindow, GLFW_KEY_W) == GLFW_PRESS;
	int downKeyState = glfwGetKey(this->glfwWindow, GLFW_KEY_S) == GLFW_PRESS;
	int leftKeyState = glfwGetKey(this->glfwWindow, GLFW_KEY_A) == GLFW_PRESS;
	int rightKeyState = glfwGetKey(this->glfwWindow, GLFW_KEY_D) == GLFW_PRESS;

	int zoomInKeyState = glfwGetKey(this->glfwWindow, GLFW_KEY_E) == GLFW_PRESS;
	int zoomOutKeyState = glfwGetKey(this->glfwWindow, GLFW_KEY_R) == GLFW_PRESS;

	float zoomAcceleration = 0.01f * zoom;
	float zoomChange = zoomAcceleration * zoomInKeyState - zoomOutKeyState * zoomAcceleration;

	zoom += zoomChange;

	float speed = 0.01f * zoom;

	float hSpeed = rightKeyState * speed + leftKeyState * speed * -1;
	float vSpeed = upKeyState * speed + downKeyState * speed * -1;

	centerX += hSpeed;
	centerY += vSpeed;

	int windowWidth, windowHeight;
	glfwGetWindowSize(this->glfwWindow, &windowWidth, &windowHeight);

	glClear(GL_COLOR_BUFFER_BIT);

	this->shader->use();

	GLint screenResolutionUniform = this->shader->getUniformLocation("screenResolution");
	glUniform2f(screenResolutionUniform, windowWidth, windowHeight);

	GLint centerOffsetUniform = this->shader->getUniformLocation("centerOffset");
	glUniform2f(centerOffsetUniform, centerX, centerY);

	GLint zoomUniform = this->shader->getUniformLocation("zoom");
	glUniform1f(zoomUniform, zoom);

	this->renderer->renderModel(this->quadModel);

	glfwSwapBuffers(this->glfwWindow);
	glfwPollEvents();
}

void ApplicationWindow::beforeLoop()
{
	this->shader = ShaderProgram::createFromFiles("res/shaders/shader.vert", "res/shaders/shader.frag");

	this->centerX = 0;
	this->centerY = 0;
	this->zoom = 4;

	float vertices[] = {
		//Top right triangle
		-1.f, 1.f, 0.f,
		1.f, 1.f, 0.f,
		1.f, -1.f, 0.f,

		//Bottom left triangle
		-1.f, 1.f, 0.f,
		-1.f, -1.f, 0.f,
		1.f, -1.f, 0.f
	};

	this->quadModel = new Model(vertices, sizeof(vertices));
	this->renderer = new ModelRenderer(); }
