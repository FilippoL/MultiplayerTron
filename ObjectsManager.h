#pragma once

#include <iostream>
#include <SDL.h>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <glew.h>
#include <windows.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include "ObjectsManager.h"
#define WIDTH 1600
#define HEIGHT 900

class ObjectsManager
{

protected:
	bool LinkToShader();

	virtual void InitialiseMaterial();
	virtual void Update(double dt) {};

	void FillBuffers( 
					 std::vector<GLfloat> Vertices, 
					 std::vector<GLfloat> Colors, 
					 std::vector<GLfloat> UVs = std::vector<GLfloat>{}, 
					 std::vector<GLuint> Indices = std::vector<GLuint>{},
					 std::vector<GLfloat> Normals = std::vector<GLfloat>{});


public:
	ObjectsManager();
	virtual ~ObjectsManager();

protected:
	void Rotate(GLfloat x, GLfloat y, GLfloat z, GLfloat degrees);
	void Scale( GLfloat x, GLfloat y, GLfloat z);
	void Translate( glm::vec3 position);
	void Reset();
	
	
protected:
	GLuint m_VAO;
	GLuint m_VertexVBO;
	GLuint m_ColorVBO;
	GLuint m_EBO;
	GLuint m_TextureVBO;
	GLuint m_NormalsVBO;
	


protected:
	GLuint shaderProgramID;
	GLint normalAttributeID;
	GLint vertexAttributeID;
	GLint colorAttributeID;
	GLint textureAttributeID;
	GLint modelUniform;
	GLint textureFlagUniformID;
	GLint FBOFlagUniformID;
	GLint lightFlagUniformID;
	GLint bloomFlagUniformID;
	GLint exposureFlagUniformID;

protected:
	GLuint materialAmbientUniformID;
	GLuint materialDiffuseUniformID;
	GLuint materialSpecularUniformID;
	GLuint materialShininessUniformID;

protected:
	glm::mat4 m_model;

protected:
	glm::vec3 m_ambient;
	glm::vec3 m_diffuse;
	glm::vec3 m_specular;

	float exposure;
protected:	
	std::vector<GLfloat>  m_vertices;
	std::vector<GLfloat>  m_colors;
	std::vector<GLfloat>  m_UVs;
	std::vector<GLuint>   m_indices;

	std::vector<GLfloat>  m_normals;

protected: 
	GLfloat shininess;

};

