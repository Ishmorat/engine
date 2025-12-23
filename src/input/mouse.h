#pragma once

#include "../gl/gl.h"
#include <bitset>

constexpr uint LAST_BUTTON = GLFW_MOUSE_BUTTON_LAST;

class Mouse {
private:
	std::bitset<LAST_BUTTON> pressed;
	std::bitset<LAST_BUTTON> changed;
	float	x;
	float	y;
	float	x_prev;
	float	y_prev;
	float	dx;									// „тобы не пересчитывать несколько раз за итерацию 
	float	dy;
	float	dx_scroll;
	float	dy_scroll;
	bool	first_move;
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
	float get_x()					const noexcept;
	float get_y()					const noexcept;
	float get_dx()					noexcept;
	float get_dy()					noexcept;
	float get_dx_scroll()			noexcept;
	float get_dy_scroll()			noexcept;
	bool is_pressed(int button);
	bool is_changed(int button);
	bool is_went_down(int button);
	bool is_went_up(int button);
};