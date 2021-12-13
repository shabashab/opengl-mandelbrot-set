#include <GL/glew.h>

#include "vertexArrays.hpp"

VertexArrays::VertexArrays()
{
	glGenVertexArrays(1, &id);
}

VertexArrays::~VertexArrays()
{
	glDeleteVertexArrays(1, &id);
}

void VertexArrays::bind()
{
	glBindVertexArray(this->id);
}

void VertexArrays::unbind()
{
	glBindVertexArray(0);
}

unsigned int VertexArrays::getId()
{
	return this->id;
}
