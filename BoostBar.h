#pragma once
#include "ObjectsManager.h"
#include "Sprite.h"
class BoostBar :
	public ObjectsManager
{
public:
	BoostBar();
	Sprite sprt;
	
	void InitialiseMaterial();
	bool &Boosting();
	bool CanBoost();
	void Update(double dt);
	bool Initialise(float x, float y, float z, int W, int H);
	void Draw();
	glm::vec3 m_position;
	float _boost;
	bool isboosting;
	int _width;
	int _height;
	virtual ~BoostBar();
	bool _canboost;
};

