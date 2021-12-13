#include <GL/glew.h>

#include "vertexBuffer.hpp"

VertexBuffer::VertexBuffer(float* vertices, int verticesCount)
{
	glGenBuffers(1, &id);

	this->vertices = vertices;
	this->verticesCount = verticesCount;
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &id);
}

void VertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, this->id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticesCount, vertices, GL_STATIC_DRAW);
}

void VertexBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

unsigned int VertexBuffer::getId()
{
	return this->id;
}

int VertexBuffer::getVerticesCount()
{
	return this->verticesCount;
}
