#include "World.h"
#include "gl_core_4_4.h"
#include "glm/ext.hpp"

void World::start()
{
	onStart();
	m_started = true;

	//Initialize the quad
	m_quad.onStart();
	m_quad.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	if (!m_tableDiffuse.load("earth_diffuse.jpg")) {
		printf("Failed to load texture.\n");
	}
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
	//The program ID
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
		printf("No shader bound.\n");

	int diffuseTextureUniform = glGetUniformLocation(program, "diffuseTexture");
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_tableDiffuse.getHandle());


	m_quad.draw();
	m_quad.onDraw();
	onDraw();

	for (Entity* entity : entities) {
		entity->draw();
	}
}

void World::end()
{
	onEnd();
	m_quad.onEnd();
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
	m_quad.onEnd();
	m_quad.end();
}
