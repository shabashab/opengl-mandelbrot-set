#pragma once

#include "window.hpp"
#include "vertexArrays.hpp"
#include "vertexBuffer.hpp"
#include "shader.hpp"

class ApplicationWindow : public Window
{
	private:
		VertexBuffer* quadVbo;
		VertexArrays* quadVao;
		Shader* whiteShader;
		
	public:
		ApplicationWindow();
		virtual void display();
		virtual void loop();
};
