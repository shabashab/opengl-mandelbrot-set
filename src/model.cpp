#include "model.hpp"

Model::Model(float* vertices, unsigned int verticesCount)
{
	this->vao = new VertexArrays();
	this->vbo = new VertexBuffer(vertices, verticesCount);

	this->vao->bind();
	this->vbo->bind();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

	this->vbo->unbind();
	this->vao->unbind();
}


VertexArrays* Model::getVao()
{
	return this->vao;
}

VertexBuffer* Model::getVbo()
{
	return this->vbo;
}
