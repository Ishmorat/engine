#include "ebo.h"

EBO::EBO() : Buffer() {}

void EBO::set_data(const std::vector<GLuint>& indices, DrawMode draw_m) {
	Buffer::set_data(DataType::INDEX, indices, draw_m);
}

void EBO::bind() {
	Buffer::bind(DataType::INDEX);
}

void EBO::unbind() {
	Buffer::unbind(DataType::INDEX);
}

EBO::~EBO() {}