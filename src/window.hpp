#pragma once
#include <GLFW/glfw3.h>

class Window
{
	protected:
		GLFWwindow* glfwWindow;
	public:
		Window(int width, int height, const char* title);
	public:
		void display();
	protected:
		virtual void loop() = 0;
		virtual void beforeLoop() {}
};
