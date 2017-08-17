

#include "../include/Graphics/Context.h"
#include "glglew.h"

#ifdef _DEBUG
#include <iostream>
void APIENTRY GL_errorCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
	GLsizei length, const GLchar *message,
	const void *userParam)
{
	std::cerr << message << std::endl;
}
#endif

bool Context::init(size_t w, size_t h, const char *title)
{
	glfwInit();

	handle = glfwCreateWindow(w, h, title, 0, 0);
	glfwMakeContextCurrent(handle);

	glewExperimental = true;
	glewInit();

	return true;
}


bool Context::step()
{
	glfwPollEvents();

	glfwSwapBuffers(handle);

	return !glfwWindowShouldClose(handle);
}


bool Context::term()
{
	glfwTerminate();
	handle = nullptr;
	return true;
}

bool Context::getKey(int key)
{
	
	return true;
}
