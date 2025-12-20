#pragma once

#include "../gl/gl.h"

class Timer {
private:
	GLfloat prev;
public:
	Timer();
	GLfloat get_time()	const noexcept;
	GLfloat get_dt()	noexcept;
};