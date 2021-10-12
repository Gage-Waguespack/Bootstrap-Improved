#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	triCount = 12;
	vertexCount = 36;

	vertices = new Vertex[vertexCount];
	//The letters are INDICES and they keep track of VERTICES
	setVertexPosition(vertices, vertexCount, 0, { -1.0f,  1.0f, -1.0f }); //A
	setVertexPosition(vertices, vertexCount, 1, {  1.0f,  1.0f,  1.0f }); //B
	setVertexPosition(vertices, vertexCount, 2, {  1.0f, -1.0f, -1.0f }); //C
	setVertexPosition(vertices, vertexCount, 3, { -1.0f, -1.0f,  1.0f }); //D
	setVertexPosition(vertices, vertexCount, 4, {  1.0f,  1.0f, -1.0f }); //E
	setVertexPosition(vertices, vertexCount, 5, { -1.0f,  1.0f,  1.0f }); //F
	setVertexPosition(vertices, vertexCount, 6, { -1.0f, -1.0f, -1.0f }); //G
	setVertexPosition(vertices, vertexCount, 7, {  1.0f, -1.0f,  1.0f }); //H

	return vertices;
}

	void Cube::setVertexPosition(Vertex* vertices, int vertexCount, int index, glm::vec3 coordinates) {
		for (int i = index; i < vertexCount; i += 8) {
			vertices[i].position = glm::vec4(coordinates * 0.5f, 1.0f);
			vertices[i].normal = glm::vec4(coordinates, 0.0f);
			vertices[i].color = m_color;
		}
	}