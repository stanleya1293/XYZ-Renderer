#include "Model.h"

Model::Model(std::vector<Vertex> vertices, glm::vec3 position, float scale) :
	m_vao(NULL),
	m_vbo(NULL),
	m_vertexCount(vertices.size()),
	m_position(position),
	m_scale(scale),
	m_model(glm::mat4(1.0f))
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * 3 * sizeof(float), &vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	m_model = glm::translate(m_model, m_position);
	m_model = glm::scale(m_model, glm::vec3(m_scale, m_scale, m_scale));
}

Model::~Model()
{

}

void Model::render(Shader shader)
{
	shader.use();
	//shader.uniformMat4("model", m_model);
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
}