#pragma once
#include "Camera.h"
class TopDown :
	public Camera
{
public:
	TopDown();
	void Initialise();

	void Update();

	~TopDown();
};

