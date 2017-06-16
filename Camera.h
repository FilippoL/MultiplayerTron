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



class Camera
{
public:
	Camera();
	void Locate();

	void Draw();


	GLint GetPositionUniform();

	~Camera();

private:
	GLint viewUniform;
	GLint projUniform;
	GLint positionUniform;

	GLint shaderProgramID;

protected:


	glm::mat4 m_view;

	glm::vec3 m_forward;
	glm::vec3 m_up;
	glm::vec3 m_move;

	glm::vec3 m_PositionCamera;

	glm::mat4 RotMatX;
	glm::mat4 RotMatY;
	
};

