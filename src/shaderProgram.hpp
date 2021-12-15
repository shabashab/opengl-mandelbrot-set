#pragma once

#include <GL/glew.h>

#include "shader.hpp"

class ShaderProgram
{
	private:
		GLuint programId;
	public:
		ShaderProgram();
		~ShaderProgram();
	public:
		void attachShader(Shader* shader);
		void link();
		GLboolean validate();
		std::string getInfoLog();

		GLuint getProgramId();
		void use();
		GLint getUniformLocation(const char* name);
	public:
		static ShaderProgram* createFromFiles(const char* vert_path, const char* frag_path);
};
