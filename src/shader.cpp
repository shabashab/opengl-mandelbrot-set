#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "shader.hpp"


ShaderCompiler* Shader::compiler;

std::string readFile(const char *file_path) {
	std::ifstream inputStream(file_path);
	std::string content((std::istreambuf_iterator<char>(inputStream)),
                      (std::istreambuf_iterator<char>()));

	return content;
}

//TODO: replace GLInt with GLenum
Shader* Shader::createFromFile(GLint shaderType, const char *sourcePath)
{
	if(compiler == nullptr)
		compiler = new ShaderCompiler();

	GLuint shaderId = glCreateShader(shaderType);

	std::ifstream inputStream(sourcePath);
	std::string content((std::istreambuf_iterator<char>(inputStream)),
                      (std::istreambuf_iterator<char>()));


	const char* src = content.c_str();
	GLint status = compiler->compileShader(shaderId, src);

	std::cout << status << std::endl;

	if(status == GL_FALSE) {
		std::string error = compiler->getShaderCompilationError(shaderId);
		std::cout << error << std::endl;

		glDeleteShader(shaderId);
		return nullptr;
	}

	return new Shader(shaderId, shaderType);
}

GLuint Shader::getShaderId()
{
	return this->shaderId;
}

GLint Shader::getShaderType()
{
	return this->shaderType;
}

Shader::Shader(GLuint shaderId, GLint type)
{
	this->shaderId = shaderId;
	this->shaderType = type;
}

Shader::~Shader()
{
	glDeleteShader(this->shaderId);
}
