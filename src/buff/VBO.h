#pragma once

#include "buffer.h"
#include "../primitives/vertex.h"

class VBO : public Buffer {
public:
	VBO();
	void set_data(const std::vector<Vertex>& vertices, DrawType draw_t);
	void bind();
	void unbind();
	~VBO();
};