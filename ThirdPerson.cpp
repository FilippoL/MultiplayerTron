#include "ThirdPerson.h"


ThirdPerson::ThirdPerson()
{
	std::cout << "Third Person Cam"<<std::endl;
}

void ThirdPerson::Initialise()
{
	m_PositionCamera = glm::vec3(0.0f, 50.0f, -50.0f);
	m_forward = glm::vec3(0.0f, 0.0f, 1.0f);
	m_up = glm::vec3(0.0f, 1.0f, 0.0f);

}

void ThirdPerson::Update(double dt, glm::vec3 rot)
{	
	
	//m_move = glm::lerp(m_PositionCamera , m_target + glm::vec3(0.0f, 5.0f, -5.0f), 0.0035f);

	m_forward = glm::vec3(sin(rot.y), -cos(glm::radians(45.0f)) /*- cos(rot.x)*/, cos(rot.y));/*+ sin(rot.x)*/// + sin(45));//glm::lerp(m_PositionCamera , m_target + glm::vec3(0.0f, 3.5f, 5.0f), 0.0035f);	

	m_forward = m_forward * glm::vec3(15);

	m_PositionCamera = m_target - m_forward;
	
	m_view  = glm::lookAt(m_PositionCamera , m_target + m_forward, m_up );
	
	//m_PositionCamera = glm::lerp(m_PositionCamera, m_target, 0.05f);

	//m_view = glm::rotate(m_view, -rot, glm::vec3(0.0,1.0,0.0));
	
	glUniform3fv(GetPositionUniform(), 1, &m_PositionCamera.x);
}


void ThirdPerson::SetTarget(glm::vec3 TargPos)
{
	m_target = TargPos;
}

ThirdPerson::~ThirdPerson()
{
}
