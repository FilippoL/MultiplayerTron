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
#include "Sprite.h"

class HUD : public ObjectsManager
{
public:
	HUD();
	~HUD();

	Sprite sprt;
	
	void InitialiseMaterial();
	void Update(double dt);
	bool Initialise(float x, float y, float z, int W, int H);
	void Draw(std::string TextureID);

};

