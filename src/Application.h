#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"
#include "Model.h"
#include "Camera.h"
#include "Shader.h"

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
