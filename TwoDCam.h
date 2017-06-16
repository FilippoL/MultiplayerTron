#pragma once
#include "Camera.h"
class TwoDCam :
	public Camera
{
public:
	TwoDCam();

	void Initialise();

	void Update();

	~TwoDCam();

};

