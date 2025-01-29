#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera();
	~Camera();
	void update();
private:
	float m_yaw;
	float m_pitch;
	glm::vec3 m_direction;
	glm::vec3 m_position;
	glm::mat4 m_view;
};

#endif