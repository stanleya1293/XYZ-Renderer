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
		Vertex {{ -0.5f,  -0.5f,  0.0f  }},
		Vertex {{ -0.5f,   0.5f,  0.0f  }},
		Vertex {{  0.5f,  -0.5f,  0.0f  }},

		Vertex {{  0.5f,  -0.5f,  0.0f  }},
		Vertex {{ -0.5f,   0.5f,  0.0f  }},
		Vertex {{  0.5f,   0.5f,  0.0f  }}
	};

	Model square(vertices, {0.0f, 0.0f, 0.0f}, 1.0f);

	Shader def("default");

	Camera camera(def);

	while (m_window.running())
	{
		square.render(def);
		m_window.update();
	}
}
