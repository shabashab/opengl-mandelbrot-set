#include <GL/glew.h>

class Shader
{
	private:
		GLuint programId;
	public:
		Shader(const char* vert_path, const char* frag_path);
		~Shader();
	private:
		GLuint load_vertex_shader(const char* file_path);
		GLuint load_frament_shader(const char* file_path);
	public:
		GLuint getProgramId();
};
