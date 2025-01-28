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
	Model(std::vector<Vertex> vertices); 
	~Model();
	void render(Shader shader);
private:
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_vertexCount;
};

#endif
