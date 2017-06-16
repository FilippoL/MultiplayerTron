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
#include "ShaderManager.h"


class Light
{
public:
	Light();
	void Update();
	void SetPositon(glm::vec3 pos);
	bool Initalise();
	glm::vec3 GetPosition();
	void Draw();

	
	~Light();

private:
	float m_intensity;

	GLuint m_VAO;
	GLuint m_vertexVBO;
	GLuint m_colorVBO;
	
	GLuint m_modelUniformID;
	GLuint m_vertexAttributeID;
	GLuint m_colorAtrributeID;
	GLuint m_lightFlagUniformID;
	GLuint m_lightColorUniform;
	GLuint m_intensityUniformID;
	GLuint m_shaderProgramID;
	GLint textureFlagUniformID;
	
	GLint lightPositionUniformID;
    GLint lightAmbientUniformID ;
    GLint lightDiffuseUniformID ;
    GLint lightSpecularUniformID;

	GLint lightFlagUniformID;


	glm::mat4 m_model;
	glm::mat4 m_color;

	glm::vec3 m_position;

	std::vector<GLfloat>  vertices;
	std::vector<GLfloat>  colors;

	glm::vec3 m_ambient;
	glm::vec3 m_diffuse;
	glm::vec3 m_specular;

	GLfloat dirX;
	GLfloat dirY;
};

