#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <sstream>
#include <fstream>

class Shader
{
public:
	Shader(std::string name);
	~Shader();
private:
	unsigned int m_shaderID;
};

#endif