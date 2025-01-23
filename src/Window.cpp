#include "Window.h"
#include <cstddef>

Window::Window() :
	m_windowID(nullptr),
	m_width(800),
	m_height(800),
	m_title("XYZ-Renderer")
{
	glfwInit();
	m_windowID = glfwCreateWindow
		(
			m_width, 
			m_height, 
			m_title,
			NULL,
			NULL
		);
	glfwMakeContextCurrent(m_windowID);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

Window::~Window()
{
	glfwDestroyWindow(m_windowID);
}

bool Window::running()
{
	if (glfwWindowShouldClose())
		return false;
	else
		return true;
}

void Window::update()
{
	glfwSwapBuffers(m_windowID);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
}
