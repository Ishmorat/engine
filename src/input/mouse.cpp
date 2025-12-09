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

void Mouse::pos_callback(GLFWwindow* window, double x, double y) {
	auto& mouse = Mouse::get_instance();
	mouse.x_prev = std::exchange(mouse.x, x);
	mouse.y_prev = std::exchange(mouse.y, y);
}

void Mouse::button_callback(GLFWwindow* window, int button, int action, int mods) {
	auto& mouse = Mouse::get_instance();
	mouse.pressed[button] = action != GLFW_RELEASE;
	mouse.changed[button] = action != GLFW_REPEAT;
}

void Mouse::wheel_callback(GLFWwindow* window, double dx, double dy) {
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
	return x - x_prev;
}

GLfloat Mouse::get_dy() const noexcept {
	return y - y_prev;
}

GLfloat Mouse::get_dx_scroll() const noexcept {
	return dx_scroll;
}

GLfloat Mouse::get_dy_scroll() const noexcept {
	return dy_scroll;
}