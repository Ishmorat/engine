#pragma once

#include "../gl/gl.h"
#include "glm/vec2.hpp"

using glm::vec2;

enum class WrapType : GLint {
	REPEAT = GL_REPEAT,
	MIRROR = GL_MIRRORED_REPEAT,
	CTOE   = GL_CLAMP_TO_EDGE,
	CTOB   = GL_CLAMP_TO_BORDER
};

enum class FilterType {
	NEAR = GL_NEAREST,
	LIN  = GL_LINEAR
};

struct TextureParams {
public:
	WrapType	wrap_S;
	WrapType	wrap_T;
	FilterType	filter_t;
	bool		have_mipmap;
public:
	TextureParams(
		WrapType wrap_S = WrapType::REPEAT, 
		WrapType wrap_T = WrapType::REPEAT, 
		FilterType filter_t = FilterType::LIN, 
		bool have_mipmap = false
	)
		: wrap_S	 { wrap_S	   }
		, wrap_T	 { wrap_T	   }
		, filter_t	 { filter_t	   }
		, have_mipmap{ have_mipmap }
	{}
};

struct Texture {
public:
	GLuint			id;
	TextureParams	params;
	GLuint			width;
	GLuint			height;
	vec2			uv_scale;
public:
	Texture();
};