#pragma once
#include "ObjectsManager.h"
#include "Sprite.h"
#include "Text.h"

class Buttons :
	public ObjectsManager
{
public:
	Buttons();
	bool Initialise(float x, float y, float z, int W, int H, std::string txt, int rows = 1);
	Sprite _sprt;
	Text _label;


	void Update(double dt);

	bool IsClicked();

	void Draw();



	int _width, _height;
	float _x, _y, _z;
	bool _clicked;
	bool _on_it;
	virtual ~Buttons();
};

