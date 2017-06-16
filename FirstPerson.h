#pragma once
#include "Camera.h"
class FirstPerson :
	public Camera
{
public:
	FirstPerson();
	void Initialise();
	glm::mat4 GetMatrix();
	void Update();
	~FirstPerson();
};

