#pragma once

#include "../gl/gl.h"
#include <glm/gtc/matrix_transform.hpp>
#include "../window/window.h"
#include "../input/keyboard.h"
#include "../input/mouse.h"

using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat4;

enum class ProjType {
	PERSP,
	ORTHO
};

enum class CameraMovement : GLuint {
	FORWARD,
	BACK,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Camera {
private:
	vec3 position;
	vec3 front;
	vec3 up;
	vec3 right;

	GLfloat fov;
	GLfloat near;
	GLfloat far;

	GLfloat speed;
	GLfloat sens;

	ProjType proj_t;
private:
	void move(CameraMovement dir, GLfloat dt);
	void rotate(GLfloat dx, GLfloat dy);
public:
	Camera();
	mat4 get_view();
	mat4 get_proj(GLfloat width, GLfloat height);
	void process_input(Window& wnd, GLfloat dt);

};