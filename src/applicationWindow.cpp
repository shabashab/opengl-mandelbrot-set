#include <GL/glew.h>
#include <iostream>

#include "applicationWindow.hpp"

ApplicationWindow::ApplicationWindow() : Window(1000, 1000, "My application")
{
	glfwSetWindowSizeCallback(this->glfwWindow, [](GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	});
}

void ApplicationWindow::loop()
{
	int windowWidth, windowHeight;
	glfwGetWindowSize(this->glfwWindow, &windowWidth, &windowHeight);

	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(this->whiteShader->getProgramId());

	GLint uniformLocation = glGetUniformLocation(this->whiteShader->getProgramId(), "screenResolution");
	glUniform2f(uniformLocation, windowWidth, windowHeight);

	this->renderer->renderModel(this->quadModel);

	glfwSwapBuffers(this->glfwWindow);
	glfwPollEvents();
}

void ApplicationWindow::beforeLoop()
{
	this->whiteShader = new Shader("res/shaders/shader.vert", "res/shaders/shader.frag");

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
	this->renderer = new ModelRenderer();
}
