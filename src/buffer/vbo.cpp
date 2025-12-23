#include "vbo.h"

VBO::VBO() : Buffer() {}

void VBO::set_data(const std::vector<Vertex>& vertices, DrawMode draw_m) {
	Buffer::set_data(DataType::VERTEX, vertices, draw_m);
}

void VBO::bind() {
	Buffer::bind(DataType::VERTEX);
}

void VBO::unbind() {
	Buffer::unbind(DataType::VERTEX);
}

VBO::~VBO() {}