#include "DragonWorld.h"

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

#pragma region Dragon
	//Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj");
	add(m_dragon);
#pragma endregion

#pragma region Cube
	//Cube
	m_cube = new Cube();
	m_cube->setColor(glm::vec4(0.6f, 0.2f, 0.4f, 1.0f));
	add(m_cube);
#pragma endregion
}

void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_dragon);
	destroy(m_cube);
}
