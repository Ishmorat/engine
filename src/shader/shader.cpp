#include "shader.h"
#include "../utils/file_reader.h"
#include <iostream>

void Shader::create(ShaderType type) {
	id = glCreateShader(static_cast<GLuint>(type));
}

void Shader::check_status() {
	const GLint sz = 512;
	GLint success;
	GLchar infoLog[sz];
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(id, sz, NULL, infoLog);
		std::cout << "Shader not compilated : " << infoLog << std::endl;
	};
}

void Shader::compile(const std::string& path) {
	FileReader fr(path);
	std::string code = fr.read();
	const char* c_str = code.c_str();
	glShaderSource(id, 1, &c_str, NULL);
	glCompileShader(id);
}

void Shader::clear() {
	glDeleteShader(id);
}

Shader::Shader(ShaderType type, const std::string& path) {
	create(type);
	compile(path);
}

GLuint Shader::get_id() const noexcept {
	return id;
}

Shader::~Shader() {
	clear();
}