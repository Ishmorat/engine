#include "camera.h"

void Camera::move(float dt) {
	auto& keyboard = Keyboard::get_instance();
	float dist = speed * dt;
	if (keyboard.is_pressed(GLFW_KEY_LEFT_SHIFT))	dist *= 2.0f;
	if (keyboard.is_pressed(GLFW_KEY_W))			position += dist * front;
	if (keyboard.is_pressed(GLFW_KEY_S))			position -= dist * front;
	if (keyboard.is_pressed(GLFW_KEY_A))			position -= dist * right;
	if (keyboard.is_pressed(GLFW_KEY_D))			position += dist * right;
	if (keyboard.is_pressed(GLFW_KEY_E))			position += dist * up;
	if (keyboard.is_pressed(GLFW_KEY_Q))			position -= dist * up;
}

void Camera::rotate() {
	auto& mouse = Mouse::get_instance();
	float dx = mouse.get_dx();
	float dy = mouse.get_dy();

	if (dx == 0.0 && dy == 0.0) return;
	dx *= sens;
	dy *= sens;

	vec3 front_ = front + (dx * right) + (dy * up);
	front = glm::normalize(front_);
	right = glm::normalize(glm::cross(front, world_up));
	up	  = glm::normalize(glm::cross(right, front));
}

Camera::Camera(const vec3& position)
	: position{ position		}
	, front	  { cfg::front		}
	, up	  { cfg::up			}
	, right	  { cfg::right		}
	, world_up{ cfg::up			}
	, fov	  { cfg::fov		}
	, near	  { cfg::near		}
	, far	  { cfg::far		}
	, speed	  { cfg::speed		}
	, sens	  { cfg::sens		}
	, proj_m  { ProjMode::PERSP }
{}

mat4 Camera::get_view() {
	return glm::lookAt(position, position + front, up);
}

mat4 Camera::get_proj(float width, float height) {
	if (proj_m == ProjMode::PERSP) {
		float ratio = width / height;
		return glm::perspective(fov, ratio, near, far);
	}
	else {
		float right  = width * 0.5;
		float left   = -right;
		float top    = height * 0.5;
		float bottom = -top;
		return glm::ortho(left, right, bottom, top, near, far);
	}
}

void Camera::process_input(float dt) {
	move(dt);
	rotate();
}
