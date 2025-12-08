#include "ebo.h"

EBO::EBO() : Buffer() {}

void EBO::set_data(const std::vector<GLuint>& indices, DrawType draw_t) {
	Buffer::set_data(DataType::INDEX, indices, draw_t);
}

void EBO::bind() {
	Buffer::bind(DataType::INDEX);
}

void EBO::unbind() {
	Buffer::unbind(DataType::INDEX);
}

EBO::~EBO() {}