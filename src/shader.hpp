#include <GL/glew.h>

#include "shaderCompiler.hpp"

class Shader
{
	private:
		GLuint shaderId;
		GLint shaderType;
	public:
		Shader(GLuint shaderId, GLint shaderType);
		~Shader();
	public:
		GLuint getShaderId();
		GLint getShaderType();

	private:
		static ShaderCompiler* compiler;
	public:
		static Shader* createFromFile(GLint shaderType, const char* sourcePath);
};
