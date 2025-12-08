#pragma once

#include "buffer.h"

class EBO : public Buffer {
public:
	EBO();
	void set_data(const std::vector<GLuint>& indices, DrawType draw_t = DrawType::STATIC);
	void bind();
	void unbind();
	~EBO();
};