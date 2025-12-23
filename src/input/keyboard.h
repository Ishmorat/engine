#pragma once

#include <bitset>
#include "../gl/gl.h"

constexpr uint LAST_KEY = GLFW_KEY_LAST;

class Keyboard {
private:
	std::bitset<LAST_KEY> pressed;
	std::bitset<LAST_KEY> changed;
private:
	Keyboard();
	~Keyboard();
public:
	Keyboard(const Keyboard&)			 = delete;
	Keyboard& operator=(const Keyboard&) = delete;
	static Keyboard& get_instance();
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	bool is_pressed(int key);
	bool is_changed(int key);
	bool is_went_down(int key);
	bool is_went_up(int key);
};