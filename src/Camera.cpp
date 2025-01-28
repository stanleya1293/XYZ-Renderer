#include "Camera.h"

Camera::Camera() :
	m_position(),
	m_direction(),
	m_view()
{
	m_direction = glm::vec3();
	m_view = glm::lookAt(m_position, m_position + glm::normalize(m_direction), glm::vec3(0.0f, 1.0f, 0.0f));

}

Camera::~Camera()
{

}