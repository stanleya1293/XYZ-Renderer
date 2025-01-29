#include "Camera.h"

Camera::Camera(Shader shader) :
	m_yaw(-90.0f),
	m_pitch(0.0f),
	m_direction(0),
	m_position(0),
	m_view(0),
	m_shader(shader)
{
	m_direction.x = (1 - sin(glm::radians(m_yaw))) * (1 - sin(glm::radians(m_pitch)));
	m_direction.y = sin(glm::radians(m_pitch));
	m_direction.z = (sin(glm::radians(m_yaw))) * (1 - sin(glm::radians(m_pitch)));

	m_view = glm::lookAt(m_position, m_position + glm::normalize(m_direction), glm::vec3(0.0f, 1.0f, 0.0f));
	
}

Camera::~Camera()
{

}

void Camera::move(float xOffset, float yOffset, float zOffset)
{
	m_position.x += xOffset;
	m_position.y += yOffset;
	m_position.z += zOffset;

}