#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <glew.h>
#include <windows.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include "ObjectsManager.h"
#include "TextureManager.h"

class Cube : public ObjectsManager
{
public:
	Cube();

	~Cube();

public:

	void InitialiseMaterial();
	bool Initialise();

	void Update(double dt);

	void Draw();


};

