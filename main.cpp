#include <cstdio>
#include <cstdlib>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

using namespace glm;

int main() {
	glewExperimental = true;	

	if(!glfwInit()) {
		printf("Failed to initialize GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 16);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	GLFWwindow* window;
	window = glfwCreateWindow(800, 600, "Hello, world", NULL, NULL);

	if(window == NULL) {
		printf("Failed to open GLFW window\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if(glewInit() != GLEW_OK) {
		printf("Failed to initialize GLEW\n");
		glfwTerminate();
		return -1;
	}

	return 0;
}
