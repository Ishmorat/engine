#include "camera.h"

Camera::Camera()
	: position{ vec3(0.0f, 0.0f, 1.0f)	}
	, front	  { vec3(0.0f, 0.0f, -1.0f) }
	, up	  { vec3(0.0f, 1.0f, 0.0f)	}
	, right	  { vec3(1.0f, 0.0f, 0.0f)	}
	, fov	  { 45.0f					}
	, near	  { 0.1f					}
	, far	  { 100.0f					}
	, speed	  { 10.0f					}
	, sens	  { 0.002f					}
	, proj_t  { ProjType::PERSP			}
{}

mat4 Camera::get_view() {
	return glm::lookAt(position, position + front, up);
}

mat4 Camera::get_proj(GLfloat width, GLfloat height) {
	if (proj_t == ProjType::PERSP) {
		GLfloat ratio = width / height;
		return glm::perspective(fov, ratio, near, far);
	}
	else {
		GLfloat right  = width * 0.5;
		GLfloat left   = -right;
		GLfloat top    = height * 0.5;
		GLfloat bottom = -top;
		return glm::ortho(left, right, bottom, top, near, far);
	}
}

void Camera::move(CameraMovement dir, GLfloat dt) {
	GLfloat dist = speed * dt;
	switch (dir) {
	case CameraMovement::FORWARD : position += dist * front;	break;
	case CameraMovement::BACK	 : position -= dist * front;	break;
	case CameraMovement::LEFT	 : position -= dist * right;	break;
	case CameraMovement::RIGHT	 : position += dist * right;	break;
	case CameraMovement::UP		 : position += dist * up;		break;
	case CameraMovement::DOWN	 : position -= dist * up;		break;
	default						 :								break;
	}
}

void Camera::rotate(GLfloat dx, GLfloat dy) {
	dx *= sens;
	dy *= sens;

	vec3 front_ = front + dx * right;
	vec3 up_ = up - dy * front_;
	front_ += dy * up;
	front = glm::normalize(front_);
	up = glm::normalize(up_);
	right = glm::normalize(glm::cross(front, up));
}

void Camera::process_input(Window& wnd, GLfloat dt) {
	auto& keyboard = Keyboard::get_instance();
	auto& mouse = Mouse::get_instance();

	if (keyboard.is_pressed(GLFW_KEY_LEFT_SHIFT)) dt *= 2.0f;

	if		(keyboard.is_pressed(GLFW_KEY_W)) move(CameraMovement::FORWARD, dt);
	else if (keyboard.is_pressed(GLFW_KEY_S)) move(CameraMovement::BACK,	dt);
	else if (keyboard.is_pressed(GLFW_KEY_A)) move(CameraMovement::LEFT,	dt);
	else if (keyboard.is_pressed(GLFW_KEY_D)) move(CameraMovement::RIGHT,	dt);
	else if (keyboard.is_pressed(GLFW_KEY_E)) move(CameraMovement::UP,		dt);
	else if (keyboard.is_pressed(GLFW_KEY_Q)) move(CameraMovement::DOWN,	dt);

	rotate(mouse.get_dx(), mouse.get_dy());
}
