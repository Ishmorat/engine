#include "mouse.h"

Mouse::Mouse()
	: x			{ 0.0f	}
	, y			{ 0.0f	}
	, x_prev	{ 0.0f	}
	, y_prev	{ 0.0f	}
	, dx_scroll	{ 0.0f	}
	, dy_scroll	{ 0.0f	}
	, first_move{ false }
{}

Mouse::~Mouse() {}

Mouse& Mouse::get_instance() {
	static Mouse instance;
	return instance;
}

void Mouse::cursor_callback(GLFWwindow* window, double x, double y) {
	auto& mouse = Mouse::get_instance();
	mouse.x_prev = std::exchange(mouse.x, x);
	mouse.y_prev = std::exchange(mouse.y, y);
	mouse.dx = mouse.x - mouse.x_prev;
	mouse.dy = mouse.y_prev - mouse.y;
}

void Mouse::button_callback(GLFWwindow* window, int button, int action, int mods) {
	auto& mouse = Mouse::get_instance();
	mouse.pressed[button] = action != GLFW_RELEASE;
	mouse.changed[button] = action != GLFW_REPEAT;
}

void Mouse::scroll_callback(GLFWwindow* window, double dx, double dy) {
	auto& mouse = Mouse::get_instance();
	mouse.dx_scroll = dx;
	mouse.dy_scroll = dy;
}

GLfloat Mouse::get_x() const noexcept {
	return x;
}

GLfloat Mouse::get_y() const noexcept {
	return y;
}

GLfloat Mouse::get_dx() const noexcept {
	return dx;
}

GLfloat Mouse::get_dy() const noexcept {
	return dy;
}

GLfloat Mouse::get_dx_scroll() noexcept {
	return std::exchange(dx_scroll, 0.0f);
}

GLfloat Mouse::get_dy_scroll() noexcept {
	return std::exchange(dy_scroll, 0.0f);
}

bool Mouse::is_pressed(int button) {
	return pressed[button];
}

bool Mouse::is_changed(int button) {
	bool res = changed[button];
	changed[button] = false;
	return res;
}

bool Mouse::is_went_down(int button) {
	return pressed[button] && is_changed(button);
}

bool Mouse::is_went_up(int button) {
	return !pressed[button] && is_changed(button);
}