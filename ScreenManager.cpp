#include "ScreenManager.h"
#include "ShaderManager.h"
#include <iostream>
#include <SDL.h>
#include <string>
#include <vector>
#include <glew.h>
#include <windows.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtx\rotate_vector.hpp>
#include <glext.h>
#include <math.h>

using namespace std;

ScreenManager::ScreenManager()
{
	m_width = 0;
	m_height = 0;
	m_context = 0;
	m_window = 0;
}

bool ScreenManager::Init(string windowloader, int w, int h, int major, int minor, bool compatible, bool fullscreen)
{
	SDL_Init(SDL_INIT_EVERYTHING); //INIT EVERYTHING

		if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL did not initialize properly" << std::endl;
		return false;
	}
								   //SETTING COLORS
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //SETTING FPS AND BUFFERING



	int compaflag = (compatible) ? SDL_GL_CONTEXT_PROFILE_COMPATIBILITY : SDL_GL_CONTEXT_PROFILE_CORE; //COMPATIBILITY MODE OR CORE MODE
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, compaflag);


	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);



	int screenflag = (fullscreen) ? SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_OPENGL;



	m_window = SDL_CreateWindow(windowloader.c_str(),
		SDL_WINDOWPOS_CENTERED, //WINDOW X IS CENTERED
		SDL_WINDOWPOS_CENTERED, //WINDOW Y IS CENTERED
		w, h, screenflag);



	m_width = w;
	m_height = h;


	//CHECK FOR ERRORS
	if (m_window == 0)
	{
		cout << "ERROR: WINDOW COULDNT BE LOADED!" << endl;
		return false;
	}

	m_context = SDL_GL_CreateContext(m_window);

	if (m_context == 0)
	{
		cout << "ERROR: CONTEXT COULDNT BE CREATED!" << endl;

		return false;
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glewExperimental = GL_TRUE;

	glEnable(GL_FRAMEBUFFER_SRGB);

	if (glewInit() != GLEW_OK) {

		std::cout << "GLEW did not initialize properly" << std::endl;
		return false;
	}


	glClearColor(m_backgroundcolor.r, m_backgroundcolor.g, m_backgroundcolor.b, 1.0f);


	return true;
}

void ScreenManager::SetBackgroundColor(float r, float g, float b)
{
	m_backgroundcolor.r = r;
	m_backgroundcolor.g = g;
	m_backgroundcolor.b = b;
}

void ScreenManager::clearScreen()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
}

void ScreenManager::SwapBuffer()
{
	SDL_GL_SwapWindow(m_window);
}

void ScreenManager::ShutDown()
{

	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void ScreenManager::ThreeDScreen(float FOV,float w,float h)
{
	glEnable(GL_DEPTH_TEST);
	shaderProgramID = Shade::Instance()->GetShaderID();
	projUniform = glGetUniformLocation(shaderProgramID, "projection");

	m_projection = glm::perspective(glm::radians((GLfloat)FOV), (GLfloat) w / (GLfloat) h , 0.1f, 50000.0f);
	glUniformMatrix4fv(projUniform, 1, GL_FALSE, &m_projection[0][0]);
}

void ScreenManager::TwoDScreen(float w,float h)
{
	glDisable(GL_DEPTH_TEST);
	shaderProgramID = Shade::Instance()->GetShaderID();
	projUniform = glGetUniformLocation(shaderProgramID, "projection");

	m_projection = glm::ortho(0.0f, w , 0.0f, h, 0.1f, 100.0f); 
	glUniformMatrix4fv(projUniform, 1, GL_FALSE, &m_projection[0][0]);
}


void ScreenManager::DisplayInfo()
{
	cout << (const char*)(glGetString(GL_VENDOR)) << endl;
	cout << (const char*)(glGetString(GL_VERSION)) << endl;
	cout << (const char*)(glGetString(GL_RENDERER)) << endl;


	GLint numExtensions;
	vector <string> extensions;

	glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);


	for (i; i < numExtensions; i++)
	{
		string s = (const char*)glGetStringi(GL_EXTENSIONS, i);
		extensions.push_back(s);
	}

	for (x; x < extensions.size(); x++)
	{
		cout << x << ":" << extensions[x] << endl;
	}

}


