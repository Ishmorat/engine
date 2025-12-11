#pragma once

#include "../gl/gl.h"
#include <vector>

enum class DataType : GLenum {
	VERTEX = GL_ARRAY_BUFFER,
	INDEX  = GL_ELEMENT_ARRAY_BUFFER
};

enum class DrawType : GLenum {
	STATIC  = GL_STATIC_DRAW,
	DYNAMIC = GL_DYNAMIC_DRAW,
	STREAM  = GL_STREAM_DRAW
};

class Buffer {
private:
	GLuint id;
public:
	Buffer();
	template <typename T>
	void set_data(DataType data_t, const std::vector<T>& input, DrawType draw_t);
	void bind(DataType data_t);
	void unbind(DataType data_t);
	~Buffer();
public:
	void create();
	void clear();
};

template <typename T>
void Buffer::set_data(DataType data_t, const std::vector<T>& input, DrawType draw_t) {
	GLuint count = input.size();
	GLuint sz = sizeof(T);
	glBufferData(static_cast<GLenum>(data_t), count * sz, input.data(), static_cast<GLenum>(draw_t));
}