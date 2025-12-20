#include "timer.h"

Timer::Timer()
	: prev{ get_time() }
{}

GLfloat Timer::get_time() const noexcept {
	return glfwGetTime();
}

GLfloat Timer::get_dt() noexcept {
	GLfloat curr = get_time();
	GLfloat dt = curr - prev;
	prev = curr;
	return dt;
}