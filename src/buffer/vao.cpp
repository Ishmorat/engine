#include "vao.h"
#include "../primitives/vertex.h"

void VAO::attrib(GLuint idx, GLint cnt, GLenum type, const void* ptr) {
	GLuint sz = sizeof(Vertex);
	glEnableVertexAttribArray(idx);
	glVertexAttribPointer(idx, cnt, type, GL_FALSE, sz, ptr);
}

VAO::VAO() : id{ 0 } {
	// create();
}

void VAO::create() {
	glGenVertexArrays(1, &id);
}

void VAO::clear() {
	glDeleteVertexArrays(1, &id);
	id = 0;
}

void VAO::set_attribs() {
	attrib(0, 3, GL_FLOAT, (void*)offsetof(Vertex, position));
	attrib(1, 3, GL_FLOAT, (void*)offsetof(Vertex, color   ));
	// attrib(2, 2, GL_FLOAT, (void*)offsetof(Vertex, texture ));
	// attrib(3, 3, GL_FLOAT, (void*)offsetof(Vertex, normal  ));
}

void VAO::bind() {
	glBindVertexArray(id);
}

void VAO::unbind() {
	glBindVertexArray(0);
}

VAO::~VAO() {
	clear();
}