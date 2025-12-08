#pragma once

#include "buffer.h"

class EBO : public Buffer {
public:
	EBO();
	void set_data(const std::vector<GLuint>& vertices, DrawType draw_t);
	void bind();
	void unbind();
	~EBO();
};