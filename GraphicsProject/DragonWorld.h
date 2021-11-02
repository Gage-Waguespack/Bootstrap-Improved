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
	PlayerCamera* m_camera = nullptr;
	Light* m_light = nullptr;
	Flashlight* m_flashlight = nullptr;
	OBJMesh* m_dragon = nullptr;
};

