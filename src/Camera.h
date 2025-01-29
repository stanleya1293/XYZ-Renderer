#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"

class Camera
{
public:
	Camera(Shader shader);
	~Camera();
	void move(float xOffset, float yOffset, float zOffset);
private:
	float m_yaw;
	float m_pitch;
	glm::vec3 m_direction;
	glm::vec3 m_position;
	glm::mat4 m_view;
	Shader m_shader;
};

#endif