#include "ThreeSixty.h"
#include "InputManager.h"



ThreeSixty::ThreeSixty()
{
	std::cout << "360 Cam"<<std::endl;
}

void ThreeSixty::Initialise()
{

	m_PositionCamera = glm::vec3(0.0f, 10.0f, -10.0f);
	m_forward = glm::vec3(0.0f, 0.0f, -1.0f);

	m_move = glm::vec3(0.0f);
	m_up = glm::vec3(0.0f, 1.0f, 0.0f);

	RotMatX = glm::rotate(RotMatX, glm::radians(-45.0f), glm::vec3(1.0f,0.0f,0.0f) );
	RotMatY = glm::rotate(RotMatY, glm::radians(180.0f), glm::vec3(0.0f,1.0f,0.0f) );
}


void ThreeSixty::Update()
{

	m_move  = glm::vec3(RotMatX * glm::vec4(m_move , 1.0f));

	m_move  = glm::vec3(RotMatY  * glm::vec4(m_move , 1.0f));

	m_PositionCamera  += m_move ;

	m_forward  = glm::vec3(RotMatX  * glm::vec4(m_forward , 1.0f));

	m_forward  = glm::vec3(RotMatY  * glm::vec4(m_forward , 1.0f));

	m_view  = glm::lookAt(m_PositionCamera  , m_PositionCamera  + m_forward , m_up );


	//	if (Input::Instance()->IsWPressed()) {m_move  = glm::vec3(0, 0, -1);}
	//else if (Input::Instance()->IsSPressed()) {m_move  = glm::vec3(0,0,1);}
	//else if (Input::Instance()->IsAPressed()) {m_move  = glm::vec3(-1,0,0);}
	//else if (Input::Instance()->IsDPressed()) {m_move  = glm::vec3(1,0,0);}
	//else { m_move  = glm::vec3(0); }

	glUniform3fv(GetPositionUniform(), 1, &m_PositionCamera.x);
		
	RotateX();
	RotateY();
	
	m_forward  = glm::vec3(0.0f, 0.0f, -1.0f);
}

void ThreeSixty::RotateX() 
{
	speed = 0.25;

	float myangle = dot(m_up , m_forward );

	GLfloat anglex = (Input::Instance()->MouseSpeed().y);
	
	
	if (myangle > 0.45 && anglex > 0.0 ||myangle < -0.45 && anglex < 0.0)
	{
		speed = 0.25;
	}

	if (myangle > 0.45 && anglex < 0.0 ||myangle < -0.45 && anglex > 0.0)
	{
		speed = 0.0;

	}
	

	RotMatX  = glm::rotate(RotMatX , glm::radians(-anglex * speed), glm::vec3(1.0f,0.0f,0.0f) );
	
}

void ThreeSixty::RotateY()
{
	GLfloat angley = (Input::Instance()->MouseSpeed().x * 0.5f);
	RotMatY  = glm::rotate(RotMatY , glm::radians(-angley), glm::vec3(0.0f,1.0f,0.0f) );
	
}

ThreeSixty::~ThreeSixty()
{
}
