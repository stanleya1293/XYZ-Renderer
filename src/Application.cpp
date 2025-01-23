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
	while (m_window.running())
	{
		m_window.update();
	}
}
