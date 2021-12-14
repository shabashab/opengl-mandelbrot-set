#pragma once

#include "shaderProgram.hpp"

class ShaderProgramBuilder
{
	private:
		ShaderProgram* program;
	public:
		ShaderProgramBuilder();
	public:
		void setFragmentShader(Shader* shader);
		void setVertexShader(Shader* shader);
		ShaderProgram* build();
};
