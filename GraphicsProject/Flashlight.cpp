#include "Flashlight.h"
#include "gl_core_4_4.h"

Flashlight::Flashlight(glm::vec3 position, glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, float innerCutOff, float outterCutOff)
{
	setPosition(position);
	setDirection(direction);
	m_ambient = ambient;
	m_diffuse = diffuse;
	m_specular = specular;
	setInnerCutOff(innerCutOff);
	setOutterCutOff(outterCutOff);
}

void Flashlight::onDraw()
{
	int program = -2;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program == -2) {
		printf("No shader bound!\n");
		return;
	}

	int lightDirection = glGetUniformLocation(program, "iDirection");
	int lightAmbient = glGetUniformLocation(program, "iAmbient");
	int lightDiffuse = glGetUniformLocation(program, "iDiffuse");
	int lightSpecular = glGetUniformLocation(program, "iSpecular");

	if (lightDirection >= 0) {
		glm::vec3 direction = getDirection();
		glUniform3f(lightDirection, direction.x, direction.y, direction.z);
	}
	if (lightAmbient >= 0) {
		glUniform3f(lightAmbient, m_ambient.x, m_ambient.y, m_ambient.z);
	}
	if (lightDiffuse >= 0) {
		glUniform3f(lightDiffuse, m_diffuse.x, m_diffuse.y, m_diffuse.z);
	}
	if (lightSpecular >= 0) {
		glUniform3f(lightSpecular, m_specular.x, m_specular.y, m_specular.z);
	}

	//Clamp the light
	float theta = glm::dot(m_direction, glm::normalize(-m_direction));
	float epsilon = m_innerCutOff - m_outterCutOff;
	float intensity = glm::clamp((theta - m_outterCutOff) / epsilon, 0.0f, 1.0f);

	//Change the intensity of the lights (leaving out ambient so that we always have light)
	setDiffuse(getDiffuse() *= intensity);
	setSpecular(getSpecular() *= intensity);
}

glm::vec3 Flashlight::getDirection()
{
	return getTransform()->getForward();
}

void Flashlight::setDirection(glm::vec3 direction)
{
	getTransform()->setForward(direction);
}
