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

class Text : public ObjectsManager
{
public:
	Text();
		
	int endline;
	int distance_y;
	int total;
	
	int start_line = 0;
	void Write(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat h, std::string Number, int lines = 1);
	void Draw();
	void Update(double dt);
	std::vector <std::string> lines;
	~Text();

private:
	glm::vec2 oneOverDimension= glm::vec2(1.0f / 16.0f, 1.0f / 16.0f);
};

