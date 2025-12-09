#pragma once

#include "../gl/gl.h"
#include "../utils/config.h"
#include "../input/keyboard.h"
#include "../input/mouse.h"

class Window {
private:
	GLFWwindow* ptr;
private:
	void init_glfw();
	void init_glew();
	void create();
	void set_viewport();
	void set_keycallback(GLFWkeyfun callback);
	void set_cursorcallback(GLFWcursorposfun callback);
	void set_buttoncallback(GLFWmousebuttonfun callback);
	void set_scrollcallback(GLFWscrollfun callback);
	void set_callbacks();
	void terminate();
	void init();
public:
	Window();
	void make_target();
	void set_should_close(bool val);
	bool should_close();
	void swap_buffers();
	~Window();
};