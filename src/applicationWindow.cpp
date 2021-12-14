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
	int windowWidth, windowHeight;
	glfwGetWindowSize(this->glfwWindow, &windowWidth, &windowHeight);

	glClear(GL_COLOR_BUFFER_BIT);

	this->shader->use();

	GLint screenResolutionUniform = this->shader->getUniformLocation("screenResolution");
	glUniform2f(screenResolutionUniform, windowWidth, windowHeight);

	GLint centerOffsetUniform = this->shader->getUniformLocation("centerOffset");
	glUniform2f(centerOffsetUniform, 0, 0);

	GLint zoomUniform = this->shader->getUniformLocation("zoom");
	glUniform1f(zoomUniform, 4);

	this->renderer->renderModel(this->quadModel);

	glfwSwapBuffers(this->glfwWindow);
	glfwPollEvents();
}

void ApplicationWindow::initShaderProgram()
{
	Shader* vertexShader = Shader::createFromFile(GL_VERTEX_SHADER, "res/shaders/shader.vert");
	Shader* fragmentShader = Shader::createFromFile(GL_FRAGMENT_SHADER, "res/shaders/shader.frag");

	ShaderProgramBuilder programBuilder;

	programBuilder.setVertexShader(vertexShader);
	programBuilder.setFragmentShader(fragmentShader);

	this->shader = programBuilder.build();

	delete vertexShader;
	delete fragmentShader;
}

void ApplicationWindow::beforeLoop()
{
	this->initShaderProgram();

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
