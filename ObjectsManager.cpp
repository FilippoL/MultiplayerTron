#pragma once

#include "ObjectsManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>


ObjectsManager::ObjectsManager()
{/*Creating objects vectors slots*/

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VertexVBO);
	glGenBuffers(1, &m_ColorVBO);
	glGenBuffers(1, &m_TextureVBO);
	glGenBuffers(1, &m_EBO);
	glGenBuffers(1, &m_NormalsVBO);

}


bool ObjectsManager::LinkToShader()
{
	
	/*Find attributes for each shader*/
	shaderProgramID = Shade::Instance()->GetShaderID();
	normalAttributeID = glGetAttribLocation(shaderProgramID, "normalIn");
	vertexAttributeID = glGetAttribLocation(shaderProgramID, "position");
	colorAttributeID = glGetAttribLocation(shaderProgramID, "colorIn");
	textureAttributeID = glGetAttribLocation(shaderProgramID, "textureIn");

	exposureFlagUniformID = glGetUniformLocation(shaderProgramID, "exposure");

	modelUniform = glGetUniformLocation(shaderProgramID, "model");
	textureFlagUniformID = glGetUniformLocation(shaderProgramID, "isTextured");
	FBOFlagUniformID = glGetUniformLocation(shaderProgramID, "isFBO");
	lightFlagUniformID = glGetUniformLocation(shaderProgramID, "isLighted");
	//bloomFlagUniformID = glGetUniformLocation(shaderProgramID, "isBloomes");




	//acquire vertex shader attribute IDs
	materialAmbientUniformID = glGetUniformLocation(shaderProgramID, "material.ambient");
	materialDiffuseUniformID = glGetUniformLocation(shaderProgramID, "material.diffuse");
	materialSpecularUniformID = glGetUniformLocation(shaderProgramID, "material.specular");
	materialShininessUniformID = glGetUniformLocation(shaderProgramID, "material.shininess");
	


	return true;
}

void ObjectsManager::InitialiseMaterial()
{
	//0.19225	0.19225	0.19225
	m_ambient.r = 0.19225;
	m_ambient.g = 0.19225;
	m_ambient.b = 0.19225;


	//0.7516448	0.22648
	m_diffuse.r = 0.75164;
	m_diffuse.g = 0.60648;
	m_diffuse.b = 0.22648;


	m_specular.r = 1.0f;
	m_specular.g = 1.0f;
	m_specular.b = 1.0f;

	shininess = 1;
}

void ObjectsManager::Rotate( GLfloat x, GLfloat y, GLfloat z, GLfloat degrees)
{/*Tranformations of each object*/
	m_model = glm::rotate(m_model, glm::radians(degrees), glm::vec3(x, y, z));
}

void ObjectsManager::Scale(GLfloat x,GLfloat y,GLfloat z)
{
	m_model = glm::scale(m_model, glm::vec3(x, y, z));
}

void ObjectsManager::Translate(glm::vec3 position)
{
	m_model = glm::translate(m_model, position); 
}

void ObjectsManager::Reset()
{
	m_model = glm::mat4(1.0f); 
}


void ObjectsManager::FillBuffers( 
								 std::vector<GLfloat> Vertices, 
								 std::vector<GLfloat> Colors, 
								 std::vector<GLfloat> UVs , 
								 std::vector<GLuint> Indices, 
								 std::vector<GLfloat> Normals)
{
	
	glBindVertexArray(m_VAO);

	//	/**********************VERTEX VBO*********************/
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexVBO);
	glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(GLfloat), &Vertices[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(vertexAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertexAttributeID);


	//	/***********************COLOR VBO*******************/
	glBindBuffer(GL_ARRAY_BUFFER, m_ColorVBO);
	glBufferData(GL_ARRAY_BUFFER, Colors.size() * sizeof(GLfloat), &Colors[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(colorAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(colorAttributeID);

	if (!Normals.empty())
	{
		//	/***********************NORMALS VBO*******************/
		glBindBuffer(GL_ARRAY_BUFFER, m_NormalsVBO);
		glBufferData(GL_ARRAY_BUFFER, Normals.size() * sizeof(GLfloat), &Normals[0], GL_DYNAMIC_DRAW);
		glVertexAttribPointer(normalAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(normalAttributeID);

	}
	
		
	if (!UVs.empty())
	{
		//	/***********************TEXTURE VBO*******************/
		glBindBuffer(GL_ARRAY_BUFFER, m_TextureVBO);
		glBufferData(GL_ARRAY_BUFFER, UVs.size() * sizeof(GLfloat), &UVs[0], GL_DYNAMIC_DRAW);
		glVertexAttribPointer(textureAttributeID, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(textureAttributeID);


		//	/***********************EBO************************/
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(GLuint), &Indices[0], GL_DYNAMIC_DRAW);
	}
	

	glBindVertexArray(0);

	glUniform1i(FBOFlagUniformID, false);


}



ObjectsManager::~ObjectsManager()
{/*Deconstruct*/
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VertexVBO);
	glDeleteBuffers(1, &m_ColorVBO);
	glDeleteBuffers(1, &m_EBO);
	glDeleteBuffers(1, &m_TextureVBO);	

	m_vertices.clear();
	m_colors.clear();
	m_UVs.clear();
	m_indices.clear();
	m_normals.clear();
}

