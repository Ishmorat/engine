#pragma once

#include "../gl/gl.h"
#include <string>

enum class ShaderType : uint {
	VERT = GL_VERTEX_SHADER,
	FRAG = GL_FRAGMENT_SHADER,
	GEOM = GL_GEOMETRY_SHADER
};

class Shader {
private:
	uint id;
private:
	void create(ShaderType type);
	void check_status();
	void compile(const std::string& path);
	void clear();
public:
	Shader(ShaderType type, const std::string& path);
	Shader(const Shader&)				= delete;						// Лучше убрать копирование, т.к. у копии остается тот же id и деструктор может удалить шейдер раньше 
	Shader& operator=(const Shader&)	= delete;
	uint get_id()						const noexcept;
	~Shader();
};