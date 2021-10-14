#include "World.h"
#include "gl_core_4_4.h"
#include "glm/ext.hpp"

void World::start()
{
	onStart();
	m_started = true;
}

void World::update(float deltaTime)
{
	if (!m_started) {
		start();
	}

	onUpdate(deltaTime);

	//Update the list of entities
	for (Entity* entity : addList) {
		entities.push_back(entity);
	}
	addList.clear();
	entities.unique();
	for (Entity* entity : removeList) {
		entities.remove(entity);
	}
	removeList.clear();
	for (Entity* entity : destroyList) {
		entities.remove(entity);
		delete entity;
	}
	destroyList.clear();

	//Update the entities
	for (Entity* entity : entities) {
		entity->update(deltaTime);
	}
}

void World::draw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
		printf("No shader bound.\n");

	int diffuseTextureUniform = glGetUniformLocation(program, "diffuseTexture");
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_marbleDiffuse.getHandle());

	m_quad.draw();
	onDraw();

	for (Entity* entity : entities) {
		entity->draw();
	}
}

void World::end()
{
	onEnd();
}

void World::add(Entity* entity)
{
	removeList.remove(entity);
	addList.push_back(entity);
}

void World::remove(Entity* entity)
{
	addList.remove(entity);
	removeList.push_back(entity);
}

void World::destroy(Entity* entity)
{
	addList.remove(entity);
	removeList.remove(entity);
	destroyList.push_back(entity);
}
