#pragma once

#include "../gl/gl.h"
#include "glm/vec2.hpp"

using glm::vec2;

enum class WrapMode : int {
	REPEAT	= GL_REPEAT,
	MIRROR	= GL_MIRRORED_REPEAT,
	CTOE	= GL_CLAMP_TO_EDGE,
	CTOB	= GL_CLAMP_TO_BORDER
};

enum class FilterMode : int {
	NEAR	= GL_NEAREST,
	LIN		= GL_LINEAR
};

struct TextureParams {
public:
	WrapMode	wrap_S;
	WrapMode	wrap_T;
	FilterMode	filter_m;
	bool		have_mipmap;
public:
	TextureParams(
		WrapMode wrap_S = WrapMode::REPEAT, 
		WrapMode wrap_T = WrapMode::REPEAT, 
		FilterMode filter_m = FilterMode::LIN, 
		bool have_mipmap = false
	)
		: wrap_S	 { wrap_S	   }
		, wrap_T	 { wrap_T	   }
		, filter_m	 { filter_m	   }
		, have_mipmap{ have_mipmap }
	{}
};

struct Texture {
public:
	uint			id;
	TextureParams	params;
	uint			width;
	uint			height;
	vec2			uv_scale;
public:
	Texture();
};