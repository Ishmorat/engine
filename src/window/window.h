#pragma once

#include "../gl/gl.h"
#include "../utils/config.h"

class Window {
private:
	GLFWwindow* ptr;
private:
	void init_glfw();
	void init_glew();
	void create();
	void set_viewport();
	void terminate();
	void init();
public:
	Window();
	void make_target();
	bool should_close();
	void set_keycallback(GLFWkeyfun callback);
	void swap_buffers();
	~Window();
};