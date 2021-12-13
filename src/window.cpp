#include "window.hpp"

Window::Window(int width, int height, const char* title)
{
	glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);	
	glfwMakeContextCurrent(glfwWindow);
}

void Window::display()
{
	while(!glfwWindowShouldClose(this->glfwWindow)) {
		loop();
	}
}
