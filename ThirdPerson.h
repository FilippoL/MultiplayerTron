#pragma once
#include "Camera.h"
#include <gtx\compatibility.hpp>

class ThirdPerson :
	public Camera
{
public:
	ThirdPerson();
	
	void Initialise();

	void Update(double dt, glm::vec3 rot);

	void SetTarget(glm::vec3 TargPos);

	~ThirdPerson();

private:
	glm::vec3 m_target;
};

