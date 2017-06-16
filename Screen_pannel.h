#pragma once
#include "ObjectsManager.h"
#include "Sprite.h"
class Screen_pannel :
	public ObjectsManager
{
public:
	Screen_pannel();

	void InitialiseMaterial();

	
	Sprite sprt;


	void Update(double dt);
	bool Initialise(float x, float y, float z, int W, int H);
	void Draw(GLuint texture);

	virtual ~Screen_pannel();
};

