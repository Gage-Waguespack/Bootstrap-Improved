#include "DragonWorld.h"
#include "gl_core_4_4.h"
#include "glm/ext.hpp"

void DragonWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

#pragma region Light
	//Light
	m_light = new Light(
		{ 1.0f, -1.0f, 1.0f },
		{0.5f, 0.5f, 0.5f, 1.0f},
		{1.0f, 1.0f, 1.0f, 1.0f},
		{1.0f, 1.0f, 1.0f, 1.0f}
	);
	add(m_light);
#pragma endregion

#pragma region Flashlight
	//Flashlight
	m_flashlight = new Flashlight(
		m_camera->getTransform()->getPosition(),
		m_camera->getTransform()->getForward(),
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 1.0f, 0.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 1.0f, 1.0f },
		12.5f,
		17.5f
	);
	add(m_flashlight);
#pragma endregion

#pragma region Dragon
	//Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj");
	add(m_dragon);
#pragma endregion
}

void DragonWorld::onUpdate(float deltaTime)
{
	m_flashlight->setPosition(m_camera->getTransform()->getPosition());
	m_flashlight->getTransform()->setForward(m_camera->getTransform()->getForward());
}

void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_flashlight);
	destroy(m_dragon);
}
