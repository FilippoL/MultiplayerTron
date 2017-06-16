#include "TopDown.h"



TopDown::TopDown()
{
		std::cout << "TopDown Cam"<<std::endl;
}

void TopDown::Initialise()
{
	
	m_PositionCamera  = glm::vec3(0.0f, 10.0f, -1.0f);
	m_forward  = glm::vec3(0.0f, 0.0f, 1.0f);

	m_move  = glm::vec3(0.0f);
	m_up  = glm::vec3(0.0f, 1.0f, 0.0f);

		
}

void TopDown::Update()
{

	RotMatX  = glm::mat4(1);
	RotMatY  = glm::mat4(1);

	m_PositionCamera  = glm::vec3(0.0f, 15.0f, 10.0f);

	RotMatX  = glm::rotate(RotMatX , glm::radians(0.5f), glm::vec3(0.0f,1.0f,0.0f) );
	RotMatY  = glm::rotate(RotMatY , glm::radians(0.0f), glm::vec3(0.0f,1.0f,0.0f) );
	
	m_forward  = glm::vec3(RotMatX  * glm::vec4(m_forward , 1.0f));
	m_forward  = glm::vec3(RotMatY  * glm::vec4(m_forward , 1.0f));

	m_view  = glm::lookAt(m_PositionCamera  , m_PositionCamera  + m_forward , m_up );
	
	m_forward  = glm::vec3(0.0f, 0.0f, -1.0f);
	
	glUniform3fv(GetPositionUniform(), 1, &m_PositionCamera .x);
}


TopDown::~TopDown()
{
}
