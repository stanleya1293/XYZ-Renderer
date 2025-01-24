#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h>
#include <vector>

#include "Shader.h"

struct Vertex
{
	float x, y, z;
};

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
