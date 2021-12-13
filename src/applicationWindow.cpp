#include <GL/glew.h>
#include <iostream>

#include "applicationWindow.hpp"

ApplicationWindow::ApplicationWindow() : Window(1000, 1000, "My application")
{
}


void ApplicationWindow::loop()
{
	int windowWidth, windowHeight;
	glfwGetWindowSize(this->glfwWindow, &windowWidth, &windowHeight);

	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(this->whiteShader->getProgramId());

	GLint uniformLocation = glGetUniformLocation(this->whiteShader->getProgramId(), "screenResolution");
	glUniform2f(uniformLocation, windowWidth, windowHeight);

	this->quadVao->bind();

	glEnableVertexAttribArray(0);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);

	glfwSwapBuffers(this->glfwWindow);
	glfwPollEvents();
}

void ApplicationWindow::display()
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
	int verticesCount = 18;

	quadVao = new VertexArrays();
	quadVbo = new VertexBuffer(vertices, verticesCount);

	quadVao->bind();
	quadVbo->bind();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

	quadVbo->unbind();
	quadVao->unbind();

	Window::display();
}
