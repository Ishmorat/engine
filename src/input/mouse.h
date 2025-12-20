#pragma once

#include "../gl/gl.h"
#include <bitset>

constexpr GLint LAST_BUTTON = GLFW_MOUSE_BUTTON_LAST;

class Mouse {
private:
	std::bitset<LAST_BUTTON> pressed;
	std::bitset<LAST_BUTTON> changed;
	GLfloat		x;
	GLfloat		y;
	GLfloat		x_prev;
	GLfloat		y_prev;
	GLfloat		dx;								// „тобы не пересчитывать несколько раз за итерацию 
	GLfloat		dy;
	GLfloat		dx_scroll;
	GLfloat		dy_scroll;
	GLboolean	first_move;
private:
	Mouse();
	~Mouse();
public:
	Mouse(const Mouse&)				= delete;
	Mouse& operator=(const Mouse&)	= delete;
	static Mouse& get_instance();
	static void cursor_callback(GLFWwindow* window, double x, double y);
	static void button_callback(GLFWwindow* window, int button, int action, int mods);
	static void scroll_callback(GLFWwindow* window, double dx, double dy);
	GLfloat get_x()					const noexcept;
	GLfloat get_y()					const noexcept;
	GLfloat get_dx()				noexcept;
	GLfloat get_dy()				noexcept;
	GLfloat get_dx_scroll()			noexcept;
	GLfloat get_dy_scroll()			noexcept;
	bool is_pressed(int button);
	bool is_changed(int button);
	bool is_went_down(int button);
	bool is_went_up(int button);
};