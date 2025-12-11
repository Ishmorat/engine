#pragma once

#include "../gl/gl.h"

class VAO {
private:
	GLuint id;
private:
	void attrib(GLuint idx, GLint cnt, GLenum type, const void* ptr);
public:
	VAO();
	void create();
	void clear();
	void set_attribs();
	void bind();
	void unbind();
	~VAO();
};