#include "TwoDCam.h"



TwoDCam::TwoDCam()
{
	std::cout << "Two Dimensional Cam"<<std::endl;
}

void TwoDCam::Initialise()
{
	m_view = glm::mat4(1);
	
}

void TwoDCam::Update()
{

	m_view = glm::mat4(1);

}

TwoDCam::~TwoDCam()
{

}
