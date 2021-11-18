#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "Flashlight.h"
#include "OBJMesh.h"

class DragonWorld : public World
{
public:
	void onStart() override;
	void onUpdate(float deltaTime) override;
	void onEnd() override;

private:
	Quad m_quad = Quad(glm::vec4(0.25f, 0.25f, 0.25f, 1.0f));
	PlayerCamera* m_camera = nullptr;
	Light* m_light = nullptr;
	Flashlight* m_flashlight = nullptr;
	OBJMesh* m_dragon = nullptr;
};

