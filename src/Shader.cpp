#include "Shader.h"

Shader::Shader(std::string name) :
	m_program(NULL)
{
	std::string vertexPath = "Shaders/" + name + "/" + name + ".vertex";
	std::string fragmentPath = "Shaders/" + name + "/" + name + ".fragment";

	std::ifstream vertexFile(vertexPath);
	std::ifstream fragmentFile(fragmentPath);

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
	glCompileShader(vShader);
	glCompileShader(fShader);

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
