#include "Application.h"

Application::Application() :
	m_window(Window())
{

}

Application::~Application()
{

}

void Application::run()
{
	std::vector<Vertex> vertices =
	{
		Vertex { -0.5f,  -0.5f,  0.0f },
		Vertex { -0.5f,   0.5f,  0.0f },
		Vertex {  0.5f,  -0.5f,  0.0f },

		Vertex {  0.5f,  -0.5f,  0.0f },
		Vertex { -0.5f,   0.5f,  0.0f },
		Vertex {  0.5f,   0.5f,  0.0f }
	};

	Model square(vertices);

	Shader def("default");



	while (m_window.running())
	{
		square.render(def);
		m_window.update();
	}
}
