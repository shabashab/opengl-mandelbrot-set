#pragma once

class VertexBuffer
{
	private:
		unsigned int id = 0;

		float* vertices;
		int verticesCount;
	public:
		VertexBuffer(float* vertices, int verticesCount);
		~VertexBuffer();
	public:
		void bind();
		void unbind();
	public:
		unsigned int getId();
		int getVerticesCount();
};
