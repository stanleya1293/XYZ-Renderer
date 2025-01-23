#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>

int main() 
{
	std::cout << "Hello World!" << std::endl;

	glfwInit();
	GLFWwindow* window = glfwCreateWindow(800, 800, "Renderer", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	
	return 0;
}
