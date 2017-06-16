#include "Camera.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtx\rotate_vector.hpp>


Camera::Camera()
{
	std::cout << "Camera Created. Camera type: ";
}

void Camera::Locate()
{
	shaderProgramID = Shade::Instance()->GetShaderID();
	viewUniform = glGetUniformLocation(shaderProgramID, "view");
	projUniform = glGetUniformLocation(shaderProgramID, "projection");
	positionUniform =  glGetUniformLocation(shaderProgramID, "CameraPos");
}

void Camera::Draw()
{
	glUniformMatrix4fv(viewUniform, 1, GL_FALSE, &m_view[0][0]);
}

GLint Camera::GetPositionUniform()
{
	return positionUniform;
}




Camera::~Camera()
{


}
