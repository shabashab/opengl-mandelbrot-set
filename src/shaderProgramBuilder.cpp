#include <stdexcept>
#include <GL/glew.h>

#include "shaderProgramBuilder.hpp"

ShaderProgramBuilder::ShaderProgramBuilder()
{
	this->program = new ShaderProgram();
}

void ShaderProgramBuilder::setFragmentShader(Shader* shader)
{
	if(shader->getShaderType() != GL_FRAGMENT_SHADER) {
		throw std::runtime_error("Given shader is not a fragment shader");
	}

	this->program->attachShader(shader);		
}

void ShaderProgramBuilder::setVertexShader(Shader* shader)
{
	if(shader->getShaderType() != GL_VERTEX_SHADER) {
		throw std::runtime_error("Given shader is not a vertex shader");
	}

	this->program->attachShader(shader);		
}

ShaderProgram* ShaderProgramBuilder::build()
{
	//TODO: Implement error checking
	this->program->link();

	return this->program;
}
