#pragma once

#include <GL/glew.h>
#include <string>

class ShaderCompiler
{
	public:
		GLint compileShader(GLuint shader, const char* src);
		std::string getShaderCompilationError(GLuint shader);
};
