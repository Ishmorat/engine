#pragma once

#include <glm/vec3.hpp>

using glm::vec3;

namespace cfg {
	// Window 
	static const unsigned int	width		= 1200;
	static const unsigned int	height		= 900;
	static const char*			title		= "Engine";

	// Camera 
	static const vec3			position	= vec3(0.0f, 0.0f, 1.0f);
	static const vec3			front		= vec3(0.0f, 0.0f, -1.0f);
	static const vec3			up			= vec3(0.0f, 1.0f, 0.0f);
	static const vec3			right		= vec3(1.0f, 0.0f, 0.0f);

	static const float			fov			= 45.0f;
	static const float			near		= 0.1f;
	static const float			far			= 100.0f;

	static const float			speed		= 10.0f;
	static const float			sens		= 0.002f;
}

namespace uniform {
	static const char*			model		= "model";
	static const char*			view		= "view";
	static const char*			projection	= "projection";
}

namespace cnst {
	static const char*			simple_vs	= "res/shaders/simple.vs";
	static const char*			simple_fs	= "res/shaders/simple.fs";
	static const char*			object_vs	= "res/shaders/object.vs";
	static const char*			object_fs	= "res/shaders/object.fs";
}