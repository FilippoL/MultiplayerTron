#pragma once
#include "ObjectsManager.h"
#include "MeshLoader.h"
#include "Light.h"
#include <deque>
#include <list>

class Wake :
	public MeshLoader
{
public:
	
	Wake();

	Light _light;

	bool Initialise();

	void InitialiseMaterial();

	void Update(glm::vec3 posIn, glm::vec3 rotatio);

	bool CollisionHappening(glm::vec3 bound);

	void Draw();


	std::deque<glm::vec3> rotation;

	std::deque<glm::vec3> m_positions;

	~Wake();
};

