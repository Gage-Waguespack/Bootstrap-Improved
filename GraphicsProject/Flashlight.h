#pragma once
#include "Entity.h"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

class Flashlight : public Entity
{
public:
    Flashlight() {}
    Flashlight(glm::vec3 position, glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, float innerCutOff, float outterCutOff);
    ~Flashlight() {}

	void onDraw() override;

	//Light Position
	glm::vec3 getPosition() { return m_position; }
	void setPosition(glm::vec3 position) { m_position = position; }
	//Light Direction
	glm::vec3 getDirection();
	void setDirection(glm::vec3 direction);
	//Ambient Color
	glm::vec4 getAmbient() { return m_ambient; }
	void setAmbient(glm::vec4 ambient) { m_ambient = ambient; }
	//Diffuse Color
	glm::vec4 getDiffuse() { return m_diffuse; }
	void setDiffuse(glm::vec4 diffuse) { m_diffuse = diffuse; }
	//Specular Color
	glm::vec4 getSpecular() { return m_specular; }
	void setSpecular(glm::vec4 specular) { m_specular = specular; }
	//Light InnerCutOff
	float getInnerCutOff() { return m_innerCutOff; }
	void setInnerCutOff(float innerCutOff) { m_innerCutOff = innerCutOff; }
	//Light OutterCutOff
	float getOutterCutOff() { return m_outterCutOff; }
	void setOutterCutOff(float outterCutOff) { m_outterCutOff = outterCutOff; }

private:
    glm::vec3  m_position = glm::vec3(0.0f);
    glm::vec3  m_direction = glm::vec3(0.0f);

	glm::vec4 m_ambient = glm::vec4(0.0f);
	glm::vec4 m_diffuse = glm::vec4(0.0f);
	glm::vec4 m_specular = glm::vec4(0.0f);

    float m_innerCutOff = 12.5f;
	float m_outterCutOff = 17.5f;
};

