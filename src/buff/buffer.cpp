#include "buffer.h"

void Buffer::create() {
	glGenBuffers(1, &id);
}

void Buffer::clear() {
	glDeleteBuffers(1, &id);
}

Buffer::Buffer() {
	create();
}

void Buffer::bind(DataType data_t) {
	glBindBuffer(static_cast<GLuint>(data_t), id);
}

void Buffer::unbind(DataType data_t) {
	glBindBuffer(static_cast<GLuint>(data_t), 0);
}

Buffer::~Buffer() {
	clear();
}