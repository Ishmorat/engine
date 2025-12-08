#pragma once

#include "shader.h"

class ShaderProgram {
private:
	GLuint id;
private:
	void create();
	void add(const Shader& sh);
	void check_status();
	void link();
	void clear();
	GLint get_uniform_location(const std::string& name);
public:
	ShaderProgram(const std::string& vs_path, const std::string& fs_path);
	ShaderProgram(const ShaderProgram&)				= delete;						// Лучше убрать копирование, т.к. у копии остается тот же id и деструктор может удалить шейдерную программу раньше 
	ShaderProgram& operator=(const ShaderProgram&)	= delete;
	GLuint get_id()									const noexcept;
	void use();
	void set(const std::string& name, GLint val);
	void set(const std::string& name, GLuint val);
	~ShaderProgram();
};