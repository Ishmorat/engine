#pragma once

#include "shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat2;
using glm::mat3;
using glm::mat4;

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
	void set(const std::string& name, GLboolean   val);
	void set(const std::string& name, GLint		  val);
	void set(const std::string& name, GLuint	  val);
	void set(const std::string& name, GLfloat	  val);
	void set(const std::string& name, const vec2& val);
	void set(const std::string& name, const vec3& val);
	void set(const std::string& name, const vec4& val);
	void set(const std::string& name, const mat2& val);
	void set(const std::string& name, const mat3& val);
	void set(const std::string& name, const mat4& val);
	~ShaderProgram();
};