#pragma once
#include <GLFW/glfw3.h>

class Window
{
	protected:
		GLFWwindow* glfwWindow;
	public:
		Window(int width, int height, const char* title);
	public:
		virtual void display();
		virtual void loop() = 0;
};
