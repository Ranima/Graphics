#pragma once

// Forward declare GLFW's window
// handling pointer typ.
struct GLFWwindow;

class Context
{
private:
	GLFWwindow *handle;

public:
	bool init(size_t w = 800, size_t = 600, const char *title = "Graphics");

	bool step();

	bool term();

	bool getKey(int key);

	bool getMouseButton(int button);

	void getMousePosition(double &x_out, double &y_out);

	double getTime();
};