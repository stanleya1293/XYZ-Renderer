#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "Shader.h"

typedef struct
{
	glm::vec3 position;
} Vertex;

class Model
{
public:
	Model(std::vector<Vertex> vertices, glm::vec3 position, float scale); 
	~Model();
	void render(Shader shader);
private:
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_vertexCount;
	glm::vec3 m_position;
	float m_scale;
	glm::mat4 m_model;
};

#endif
