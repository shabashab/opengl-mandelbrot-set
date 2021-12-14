#pragma once

#include "window.hpp"
#include "vertexArrays.hpp"
#include "vertexBuffer.hpp"
#include "model.hpp"
#include "modelRenderer.hpp"
#include "shaderProgram.hpp"

class ApplicationWindow : public Window
{
	private:
		Model* quadModel;
		ModelRenderer* renderer;
		ShaderProgram* shader;
		
	private:
		void initShaderProgram();
	public:
		ApplicationWindow();
	protected:
		virtual void loop();
		virtual void beforeLoop();
};
