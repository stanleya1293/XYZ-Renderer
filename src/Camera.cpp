#include "Camera.h"

Camera::Camera(Shader shader) :
	m_yaw(-90.0f),
	m_pitch(0.0f),
	m_direction(0),
	m_position(0),
	m_view(glm::mat4(1.0f)),
	m_projection(glm::mat4(1.0f)),
	m_shader(shader)
{
	m_direction.x = (1 - sin(glm::radians(m_yaw))) * (1 - sin(glm::radians(m_pitch)));
	m_direction.y = sin(glm::radians(m_pitch));
	m_direction.z = (sin(glm::radians(m_yaw))) * (1 - sin(glm::radians(m_pitch)));

	m_view = glm::lookAt(m_position, m_position + glm::normalize(m_direction), glm::vec3(0.0f, 1.0f, 0.0f));
	m_projection = glm::perspective(glm::radians(45.0f), (float) 800.0f / (float) 800.0f, 0.1f, 100.0f);
	shader.uniformMat4("view", m_view);
	shader.uniformMat4("projection", m_projection);
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