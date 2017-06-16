#include "Light.h"
#include "ShaderManager.h"
#include "InputManager.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
//#include "..\Development Libraries\ASSIMP\include\light.h"


Light::Light()
{
	
	std::cout << "Light generated."<<std::endl;

}

void Light::Update()
{

	m_ambient = glm::vec3(0.005,0.005,0.015);
	m_diffuse = glm::vec3(0.0, 0.0, 0.01);
	m_specular = glm::vec3(0.00, 0.0, 0);


	m_model = glm::mat4(1);	
}

void Light::SetPositon(glm::vec3 pos)
{
	m_position = pos;
	m_model = glm::translate(m_model, m_position);
}


bool Light::Initalise()
{

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_vertexVBO);
	glGenBuffers(1, &m_colorVBO);

	GLint shaderProgramID = Shade::Instance()->GetShaderID();

	m_vertexAttributeID = glGetAttribLocation(shaderProgramID, "position");
	m_colorAtrributeID = glGetAttribLocation(shaderProgramID, "colorIn");
	lightFlagUniformID = glGetUniformLocation(shaderProgramID, "isLighted");
	m_modelUniformID = glGetUniformLocation(shaderProgramID, "model");
	textureFlagUniformID = glGetUniformLocation(shaderProgramID, "isTextured");


	lightPositionUniformID = glGetUniformLocation(shaderProgramID, "light.position");
	lightAmbientUniformID = glGetUniformLocation(shaderProgramID, "light.ambient");
	lightDiffuseUniformID = glGetUniformLocation(shaderProgramID, "light.diffuse");
	lightSpecularUniformID = glGetUniformLocation(shaderProgramID, "light.specular");


	/*first pos and color*/
	vertices.push_back(0.0f);
	vertices.push_back(0.0f);
	vertices.push_back(0.0f);


	colors.push_back(1.0f);
	colors.push_back(0.0f);
	colors.push_back(0.0f);

	/*Fiil buffers*/
	glBindVertexArray(m_VAO);


	//	/**********************VERTEX VBO*********************/
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexVBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(m_vertexAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(m_vertexAttributeID);


	//	/***********************COLOR VBO*******************/
	glBindBuffer(GL_ARRAY_BUFFER, m_colorVBO);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(GLfloat), &colors[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(m_colorAtrributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(m_colorAtrributeID);

	glBindVertexArray(0);


	if (m_vertexAttributeID < 0||m_colorAtrributeID < 0||lightFlagUniformID < 0||m_modelUniformID < 0||textureFlagUniformID < 0||
		lightPositionUniformID < 0||lightAmbientUniformID < 0||lightDiffuseUniformID < 0||lightSpecularUniformID < 0||
		vertices.empty() || colors.empty() || !m_VAO)
	{
		return false;
	}

	return true;
}

glm::vec3 Light::GetPosition()
{
	return m_position;
}

void Light::Draw()
{
	glUniform3fv(lightPositionUniformID, 1, &m_position.x);
	glUniform3fv(lightAmbientUniformID, 1, &m_ambient.r);
	glUniform3fv(lightDiffuseUniformID, 1, &m_diffuse.r);
	glUniform3fv(lightSpecularUniformID, 1, &m_specular.r);
	glUniformMatrix4fv(m_modelUniformID, 1, GL_FALSE, &m_model[0][0]);

	glUniform1i(lightFlagUniformID, false);
	glUniform1i(textureFlagUniformID, false);
	

	glPointSize(0.0F);


	glBindVertexArray(m_VAO);
	glDrawArrays(GL_POINTS, 0, 1);
	glBindVertexArray(0);

	
}


Light::~Light()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_vertexVBO);
	glDeleteBuffers(1, &m_colorVBO);
}
