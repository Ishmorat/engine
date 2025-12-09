#include "keyboard.h"

Keyboard::Keyboard() {}

Keyboard::~Keyboard() {}

Keyboard& Keyboard::get_instance() {
	static Keyboard instance;
	return instance;
}

void Keyboard::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	auto& keyboard = Keyboard::get_instance();
	keyboard.pressed[key] = action != GLFW_RELEASE;
	keyboard.changed[key] = action != GLFW_REPEAT;
}

bool Keyboard::is_pressed(int key) {
	return pressed[key];
}

bool Keyboard::is_changed(int key) {
	bool res = changed[key];
	changed[key] = false;
	return res;
}

bool Keyboard::is_went_down(int key) {
	return pressed[key] && is_changed(key);
}

bool Keyboard::is_went_up(int key) {
	return !pressed[key] && is_changed(key);
}