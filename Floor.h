#pragma once
#include "ObjectsManager.h"
#include "TextureManager.h"
#include "Sprite.h"

class Floor : public ObjectsManager
{
public:
	Floor();
	~Floor();

	Sprite sprt;

	void InitialiseMaterial();
	void Update(double dt);
	bool Initialise(float x, float y, float z, int W, int H);
	void Draw(std::string TextureID);
	float _w;

};

