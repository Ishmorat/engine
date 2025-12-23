#pragma once

#include "../gl/gl.h"

class Timer {
private:
	float prev;
public:
	Timer();
	float get_time()	const noexcept;
	float get_dt()		noexcept;
};