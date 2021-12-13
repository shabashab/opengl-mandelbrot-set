#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "shader.hpp"

std::string readFile(const char *file_path) {
	std::ifstream inputStream(file_path);
	std::string content((std::istreambuf_iterator<char>(inputStream)),
                      (std::istreambuf_iterator<char>()));

	return content;
}

GLuint Shader::load_vertex_shader(const char* file_path)
{
	GLuint shader = glCreateShader(GL_VERTEX_SHADER);

	std::string shader_src = readFile(file_path);
	const char *shader_src_c_str = shader_src.c_str();

	GLint compilation_status = 0;

	//Compiling the shader
	std::cout << "Compiling vertex shader " << file_path << "..." << std::endl;
	glShaderSource(shader, 1, &shader_src_c_str, NULL);

	//Compiling the shader
	glCompileShader(shader);

	//Checking the shader
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compilation_status);

	if(compilation_status == GL_FALSE) {
		std::cout << "Vertex shader " << file_path << " compilation failed!" << std::endl;

		GLint logLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

		std::vector<GLchar> errorLog(logLength);
		glGetShaderInfoLog(shader, logLength, &logLength, &(errorLog[0]));

		std::cout << &errorLog[0] << std::endl;

		glDeleteShader(shader);

		return 0;
	}

	std::cout << "Vertex shader " << file_path << " compiled successfully" << std::endl;

	return shader;
}

GLuint Shader::load_frament_shader(const char* file_path)
{
	GLuint shader = glCreateShader(GL_FRAGMENT_SHADER);

	std::string shader_src = readFile(file_path);
	const char *shader_src_c_str = shader_src.c_str();

	GLint compilation_status = 0;

	//Compiling the shader
	std::cout << "Compiling fragment shader " << file_path << "..." << std::endl;
	glShaderSource(shader, 1, &shader_src_c_str, NULL);

	//Compiling the shader
	glCompileShader(shader);

	//Checking the shader
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compilation_status);

	if(compilation_status == GL_FALSE) {
		std::cout << "Fragment shader " << file_path << " compilation failed!" << std::endl;

		GLint logLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

		std::vector<GLchar> errorLog(logLength);
		glGetShaderInfoLog(shader, logLength, &logLength, &(errorLog[0]));

		std::cout << &errorLog[0] << std::endl;

		glDeleteShader(shader);

		return 0;
	}

	std::cout << "Fragment shader " << file_path << " compiled successfully" << std::endl;

	return shader;
};

Shader::Shader(const char* vert_path, const char* frag_path)
{
	GLuint vertexShader = this->load_vertex_shader(vert_path);
	GLuint fragmentShader = this->load_frament_shader(frag_path);

	GLuint program = glCreateProgram();

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);

	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	this->programId = program;
}

GLuint Shader::getProgramId()
{
	return this->programId;
}
