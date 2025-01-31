#include "Shader.h"

#include <iostream>

Shader::Shader(std::string name) :
	m_program(NULL)
{
	std::string vertexPath = "../../../Shaders/" + name + "/" + name + ".vertex";
	std::string fragmentPath = "../../../Shaders/" + name + "/" + name + ".fragment";

	std::ifstream vertexFile(vertexPath);
	std::ifstream fragmentFile(fragmentPath);

	if (!vertexFile)
	{
		std::cout << "Invalid vertex file path" << std::endl;
	}
	if (!fragmentFile)
	{
		std::cout << "Invalid fragment file path" << std::endl;
	}

	std::stringstream vertexStream;
	std::stringstream fragmentStream;
	vertexStream << vertexFile.rdbuf();
	fragmentStream << fragmentFile.rdbuf();
	
	std::string vertexSrcCode = vertexStream.str();
	std::string fragmentSrcCode = fragmentStream.str();

	const char* vertexSrc = vertexSrcCode.c_str();
	const char* fragmentSrc = fragmentSrcCode.c_str();

	unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vShader, 1, &vertexSrc, NULL);
	glShaderSource(fShader, 1, &fragmentSrc, NULL);
	
	int vSuccess;
	glCompileShader(vShader);
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vSuccess);
	if (!vSuccess)
	{
		std::cout << "Vertex shader error compilation" << std::endl;
	}

	int fSuccess;
	glCompileShader(fShader);
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &fSuccess);
	if (!fSuccess)
	{
		std::cout << "Fragment shader error compilation" << std::endl;
	}

	m_program = glCreateProgram();
	glAttachShader(m_program, vShader);
	glAttachShader(m_program, fShader);
	glLinkProgram(m_program);

	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

Shader::~Shader()
{
	glDeleteProgram(m_program);
}

void Shader::use()
{
	glUseProgram(m_program);
}

void Shader::uniformMat4(std::string name, glm::mat4 data)
{
	glUniformMatrix4fv(glGetUniformLocation(m_program, name.c_str()), 1, GL_FALSE, glm::value_ptr(data));
}
