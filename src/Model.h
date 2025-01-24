#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h>
#include <vector>

struct Vertex
{
	float x, y, z;
};

class Model
{
public:
	Model(std::vector<Vertex> vertices); 
	~Model();
	void render(unsigned int shader);
private:
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_vertex_count;
};

#endif
