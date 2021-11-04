#pragma once
#include "Entity.h"
#include "Camera.h"
#include "Quad.h"
#include "Texture.h"
#include "Shader.h"
#include <list>

class World
{
public:
	World() {}
	~World() {}

	void start();
	void update(float deltaTime);
	void draw();
	void end();

	virtual void onStart() {}
	virtual void onUpdate(float deltaTime) {}
	virtual void onDraw() {}
	virtual void onEnd() {}

	void add(Entity* entity);
	void remove(Entity* entity);
	void destroy(Entity* entity);

	Camera* getCamera() { return m_camera; }
	void setCamera(Camera* camera) { m_camera = camera; }

private:
	Quad m_quad = Quad(glm::vec4(0.25f, 0.25f, 0.25f, 0.25f));
	aie::Texture m_tableDiffuse;
	Camera* m_camera = nullptr;

	std::list<Entity*> entities;
	std::list<Entity*> addList;
	std::list<Entity*> removeList;
	std::list<Entity*> destroyList;

	bool m_started = false;
};

