class VertexArrays
{
	private:
		unsigned int id = 0;
	public:
		VertexArrays();
		~VertexArrays();
	public:
		void bind();
		void unbind();
	public:
		unsigned int getId();
};
