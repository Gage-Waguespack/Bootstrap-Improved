#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount)
{
	glm::vec4 forwardNormal = { 0.0f,0.0f,1.0f,0.0f };
	glm::vec4 rightNormal = { 1.0f,0.0f,0.0f,0.0f };
	glm::vec4 upNormal = { 0.0f, 1.0f, 0.0f, 0.0f };

	Vertex* vertices = nullptr;
	vertexCount = 8;
	vertices = new Vertex[vertexCount];

	vertices[0].position = { -1.0f,1.0f,-1.0f,1.0f };//a
	vertices[0].normal = { -1.0f,1.0f,-1.0f,0.0f };//a

	vertices[1].position = { -1.0f,1.0f,1.0f,1.0f };//b
	vertices[1].normal = { -1.0f,1.0f,1.0f,0.0f };//b

	vertices[2].position = { 1.0f,1.0f,-1.0f,1.0f };//c
	vertices[2].normal = { 1.0f,1.0f,-1.0f,0.0f };//c

	vertices[3].position = { 1.0f,1.0f,1.0f,1.0f };//d
	vertices[3].normal = { 1.0f,1.0f,1.0f,0.0f };//d

	vertices[4].position = { 1.0f,-1.0f,1.0f,1.0f };//e
	vertices[4].normal = { 1.0f,-1.0f,1.0f,0.0f };//e

	vertices[5].position = { 1.0f,-1.0f,-1.0f,1.0f };//f
	vertices[5].normal = { 1.0f,-1.0f,-1.0f,0.0f };//f

	vertices[6].position = { -1.0f,-1.0f,1.0f,1.0f };//g
	vertices[6].normal = { -1.0f,-1.0f,1.0f,0.0f };//g

	vertices[7].position = { -1.0f,-1.0f,-1.0f,1.0f };//h
	vertices[7].normal = { -1.0f,-1.0f,-1.0f,0.0f };//h

	for (int i = 0; i < vertexCount; i++) {
		vertices[i].color = m_color;
	}
	return vertices;
}

void Cube::setVertexPosition(Vertex* verticies, int vertexCount, int index, glm::vec3 position)
{
	for (int i = index; i < vertexCount; i += 8) {
		verticies[i].position = glm::vec4(position * 0.5f, 1.0f);
		verticies[i].normal = glm::vec4(position, 0.0f);
		verticies[i].color = m_color;
	}
}

unsigned int* Cube::generateIndices(unsigned int& indexCount)
{
	//Set the number of indices
	indexCount = 36;

	unsigned int* indices = new unsigned int[indexCount] {
			//Top
			0, 1, 2,
			3, 1, 2,

			//Right
			0, 1, 7,
			6, 1, 7,
	
			//Left
			0, 2, 5,
			0, 7, 5,

			//Front
			2, 3, 4,
			2, 4, 5,

			//Bottom
			4, 5, 7,
			4, 7, 6,

			//back
			3, 1, 6,
			3, 6, 4
	};

	return indices;
}