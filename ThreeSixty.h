#pragma once
#include "Camera.h"
class ThreeSixty :
	public Camera
{
public:
	ThreeSixty();
	
	void Initialise();

	void Update();

	void RotateX();

	void RotateY();

	float speed;

	~ThreeSixty();

};
