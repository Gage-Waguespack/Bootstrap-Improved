#include "Flashlight.h"
#include "gl_core_4_4.h"

Flashlight::Flashlight(glm::vec3 position, glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, float cutOff)
{

}


glm::vec3 Flashlight::getDirection()
{
	return getTransform()->getForward();
}

void Flashlight::setDirection(glm::vec3 direction)
{
	getTransform()->setForward(direction);
}
