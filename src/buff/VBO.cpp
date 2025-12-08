#include "VBO.h"

VBO::VBO() : Buffer() {}

void VBO::set_data(const std::vector<Vertex>& vertices, DrawType draw_t) {
	Buffer::set_data(DataType::VERTEX, vertices, draw_t);
}

void VBO::bind() {
	Buffer::bind(DataType::VERTEX);
}

void VBO::unbind() {
	Buffer::unbind(DataType::VERTEX);
}

VBO::~VBO() {}