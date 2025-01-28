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
private:
	glm::vec3 m_position;
	glm::vec3 m_direction;
	glm::mat4 m_view;
};

#endif