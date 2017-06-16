#pragma once

#include "TextureManager.h"
#include "MeshLoader.h"

class SkyDome :
	public MeshLoader
{
public:
	SkyDome();

	void InitialiseMaterial();

	bool Initialise(const char * Obj, std::string texture);
	

	void Spin(float dt);

	void Draw();

	virtual ~SkyDome();
};

