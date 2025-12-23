#include "shader_program.h"
#include <iostream>

void ShaderProgram::create() {
	id = glCreateProgram();
}

void ShaderProgram::add(const Shader& sh) {
	glAttachShader(id, sh.get_id());
}

void ShaderProgram::check_status() {
	const int sz = 512;
	int success;
	char infoLog[sz];
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

int ShaderProgram::get_uniform_location(const std::string& name) {
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

uint ShaderProgram::get_id() const noexcept {
	return id;
}

void ShaderProgram::use() {
	glUseProgram(id);
}

void ShaderProgram::set(const std::string& name, bool val) {
	glUniform1i(get_uniform_location(name), static_cast<GLint>(val));
}

void ShaderProgram::set(const std::string& name, int val) {
	glUniform1i(get_uniform_location(name), val);
}

void ShaderProgram::set(const std::string& name, uint val) {
	glUniform1ui(get_uniform_location(name), val);
}

void ShaderProgram::set(const std::string& name, float val) {
	glUniform1f(get_uniform_location(name), val);
}

void ShaderProgram::set(const std::string& name, const vec2& val) {
	glUniform2fv(get_uniform_location(name), 1, glm::value_ptr(val));
}

void ShaderProgram::set(const std::string& name, const vec3& val) {
	glUniform3fv(get_uniform_location(name), 1, glm::value_ptr(val));
}

void ShaderProgram::set(const std::string& name, const vec4& val) {
	glUniform4fv(get_uniform_location(name), 1, glm::value_ptr(val));
}

void ShaderProgram::set(const std::string& name, const mat2& val) {
	glUniformMatrix2fv(get_uniform_location(name), 1, GL_FALSE, glm::value_ptr(val));
}

void ShaderProgram::set(const std::string& name, const mat3& val) {
	glUniformMatrix3fv(get_uniform_location(name), 1, GL_FALSE, glm::value_ptr(val));
}

void ShaderProgram::set(const std::string& name, const mat4& val) {
	glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, glm::value_ptr(val));
}

ShaderProgram::~ShaderProgram() {
	clear();
}