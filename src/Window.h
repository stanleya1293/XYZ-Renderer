#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window 
{
public:
	Window(); //TODO: might want to make resizeable
	~Window();
	bool running();
	void update();
private:
	GLFWwindow* m_windowID;
	int m_width, m_height;
	char* m_title;
};

#endif
