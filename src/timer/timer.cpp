#include "timer.h"

Timer::Timer()
	: prev{ get_time() }
{}

float Timer::get_time() const noexcept {
	return glfwGetTime();
}

float Timer::get_dt() noexcept {
	float curr = get_time();
	float dt = curr - prev;
	prev = curr;
	return dt;
}