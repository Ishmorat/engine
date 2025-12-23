#pragma once

#include "buffer.h"

class EBO : public Buffer {
public:
	EBO();
	void set_data(const std::vector<GLuint>& indices, DrawMode draw_m = DrawMode::STATIC);
	void bind();
	void unbind();
	~EBO();
};