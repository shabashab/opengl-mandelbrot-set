#include <iostream>

#include "shaderProgram.hpp"
#include "shaderProgramBuilder.hpp"

ShaderProgram::ShaderProgram()
{
	this->programId = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(this->programId);
}

void ShaderProgram::attachShader(Shader* shader)
{
	glAttachShader(this->programId, shader->getShaderId());
}

void ShaderProgram::link()
{
	glLinkProgram(this->programId);
}

void ShaderProgram::use()
{
	glUseProgram(this->programId);
}

GLint ShaderProgram::getUniformLocation(const char *name)
{
	return glGetUniformLocation(this->programId, name);
}


GLboolean ShaderProgram::validate()
{
	glValidateProgram(this->programId);

	GLint result;
	glGetProgramiv(this->programId, GL_VALIDATE_STATUS, &result);

	return (GLboolean)result;
}

std::string ShaderProgram::getInfoLog()
{
	GLint len;	
	glGetProgramiv(this->programId, GL_INFO_LOG_LENGTH, &len);

	GLchar* data = new GLchar[len];
	glGetProgramInfoLog(this->programId, len, NULL, data);

	return std::string(data);
}

GLuint ShaderProgram::getProgramId()
{
	return this->programId;
}

ShaderProgram* ShaderProgram::createFromFiles(const char* vert_path, const char* frag_path)
{
	Shader* vertexShader = Shader::createFromFile(GL_VERTEX_SHADER, vert_path);
	Shader* fragmentShader = Shader::createFromFile(GL_FRAGMENT_SHADER, frag_path);

	ShaderProgramBuilder programBuilder;

	programBuilder.setVertexShader(vertexShader);
	programBuilder.setFragmentShader(fragmentShader);

	ShaderProgram* program = programBuilder.build();

	delete vertexShader;
	delete fragmentShader;

	return program;
}
