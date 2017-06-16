#pragma once
#include "ObjectsManager.h"
#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <glew.h>
#include <windows.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>


class MeshLoader : public ObjectsManager
{
public:
	MeshLoader();
	bool LoadModel(const char* Path_to_File);
	void InitialiseMesh(std::vector<GLfloat>  &vertices,std::vector<GLfloat>  &Colors,std::vector<GLfloat>   &UVs,std::vector<GLuint>   &indices, std::vector<GLfloat>   &normals);

	~MeshLoader();

};
