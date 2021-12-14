#include <iostream>

#include "shaderCompiler.hpp"

GLint ShaderCompiler::compileShader(GLuint shader, const char *src)
{
	GLint compilationStatus = 0;

	glShaderSource(shader, 1, &src, NULL);

	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compilationStatus);

	return compilationStatus;
}

std::string ShaderCompiler::getShaderCompilationError(GLuint shader)
{
		GLint logLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

		GLchar *errorLog = new GLchar[logLength];
		glGetShaderInfoLog(shader, logLength, &logLength, &(errorLog[0]));

		return std::string(errorLog);
}
