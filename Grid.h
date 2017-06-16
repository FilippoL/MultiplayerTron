#pragma once
#include "ObjectsManager.h"

class Grid : public ObjectsManager
{
public:
	Grid();
	bool Initialise(int size);
	void Draw();
	~Grid();

};

