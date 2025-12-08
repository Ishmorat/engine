#include "shader_program.h"
#include <iostream>

void ShaderProgram::create() {
	id = glCreateProgram();
}

void ShaderProgram::add(const Shader& sh) {
	glAttachShader(id, sh.get_id());
}

void ShaderProgram::check_status() {
	const GLint sz = 512;
	GLint success;
	GLchar infoLog[sz];
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(id, 512, NULL, infoLog);
		std::cout << "Shader program not linked : " << infoLog << std::endl;
	}
}

void ShaderProgram::link() {
	glLinkProgram(id);
}

void ShaderProgram::clear() {
	glDeleteProgram(id);
}

GLint ShaderProgram::get_uniform_location(const std::string& name) {
	return glGetUniformLocation(id, name.c_str());
}

ShaderProgram::ShaderProgram(const std::string& vs_path, const std::string& fs_path) {
	create();
	Shader vs(ShaderType::VERT, vs_path);
	Shader fs(ShaderType::FRAG, fs_path);
	add(vs);
	add(fs);
	link();
}

GLuint ShaderProgram::get_id() const noexcept {
	return id;
}

void ShaderProgram::use() {
	glUseProgram(id);
}

void ShaderProgram::set(const std::string& name, GLint val) {
	glUniform1i(get_uniform_location(name), val);
}

void ShaderProgram::set(const std::string& name, GLuint val) {
	glUniform1ui(get_uniform_location(name), val);
}

ShaderProgram::~ShaderProgram() {
	clear();
}