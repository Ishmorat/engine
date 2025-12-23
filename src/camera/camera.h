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

enum class ProjMode {
	PERSP,
	ORTHO
};

enum class CameraMovement {
	FORWARD,
	BACK,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Camera {
private:
	vec3	 position;
	vec3	 front;
	vec3	 up;
	vec3	 right;
	vec3	 world_up;

	float	 fov;
	float	 near;
	float	 far;

	float	 speed;
	float	 sens;

	ProjMode proj_m;
private:
	void move(float dt);
	void rotate();
public:
	Camera(const vec3& position = cfg::position);
	mat4 get_view();
	mat4 get_proj(float width, float height);
	void process_input(float dt);
};