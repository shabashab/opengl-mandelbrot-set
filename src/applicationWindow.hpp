#pragma once

#include "window.hpp"
#include "vertexArrays.hpp"
#include "vertexBuffer.hpp"
#include "shader.hpp"
#include "model.hpp"
#include "modelRenderer.hpp"

class ApplicationWindow : public Window
{
	private:
		Model* quadModel;
		Shader* whiteShader;
		ModelRenderer* renderer;
		
	public:
		ApplicationWindow();
	protected:
		virtual void loop();
		virtual void beforeLoop();
};
