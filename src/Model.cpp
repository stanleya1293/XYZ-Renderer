#include "Model.h"

Model::Model(std::vector<Vertex> vertices) :
	m_vao(NULL),
	m_vbo(NULL),
	m_vertexCount(vertices.size())
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * 3 * sizeof(float), &vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), (void*)0); //needs to be done in a renderer object
	glEnableVertexAttribArray(0);
}

Model::~Model()
{

}

void Model::render(Shader shader)
{
	shader.use();
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
}