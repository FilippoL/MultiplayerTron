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


class Sprite 
{
public:
	Sprite();
	~Sprite();

public:
	bool Fill(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat h, std::vector<GLfloat>& v, 
		std::vector<GLfloat>& c, 
		std::vector<GLfloat>& uv, 
		std::vector<GLuint>& ind, 
		std::vector<GLfloat>& norm = std::vector<GLfloat>{} , bool Lighted = false);


	void SetColor(glm::vec3 color);
	glm::vec3 _color;
	void Flip();

	bool flipped;

};

