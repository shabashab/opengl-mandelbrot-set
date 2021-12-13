#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <GL/glut.h>

#include "window.hpp"
#include "applicationWindow.hpp"

using namespace glm;

void fatal(const char* err, int exitCode)
{
	std::cerr << err << std::endl;
	exit(exitCode);
}

int main() 
{
	if(!glfwInit())
		fatal("An error happened on glfw initialization", 1);

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

	Window* window = new ApplicationWindow();

	glewExperimental = true;	

	if(glewInit() != GLEW_OK) {
		glfwTerminate();
		fatal("An error occurred on loading glew", 2);
	}

	std::cout << "Using glew version " << glewGetString(GLEW_VERSION) << std::endl;

	window->display();

	glfwTerminate();

	return 0;
}
