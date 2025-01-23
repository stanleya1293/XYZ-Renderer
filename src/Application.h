#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"

class Application 
{
public:
	Application();
	~Application();
	void run();
private:
	Window m_window;
};

#endif
