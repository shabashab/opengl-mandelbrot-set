#pragma once

#include <GL/glew.h>

#include "vertexArrays.hpp"
#include "vertexBuffer.hpp"

class Model
{
	private:
		VertexArrays* vao;
		VertexBuffer* vbo;
	public:
		Model(float* vertices, unsigned int verticesCount);
	public:
		VertexArrays* getVao();
		VertexBuffer* getVbo();
};
