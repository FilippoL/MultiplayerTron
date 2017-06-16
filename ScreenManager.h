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
#include "Singleton.h"

#define WIDTH 1600
#define HEIGHT 900

class ScreenManager
{
	friend class Singleton<ScreenManager>;
public:
	

	bool Init(std::string windowloader, int w, int h, int major, int minor, bool compatible, bool fullscreen);

	void SetBackgroundColor(float r, float g, float b);
	void clearScreen();
	void SwapBuffer();
	void ShutDown();
	void DisplayInfo();

	void ThreeDScreen(float FOV,float w,float h);
	void TwoDScreen(float w,float h);
	
public:
	int i;
	int x;


private:
	ScreenManager();
	ScreenManager(const ScreenManager&);
	ScreenManager& operator=(const ScreenManager&);

	glm::mat4 m_projection;

	glm::vec3 m_backgroundcolor;

	int m_width;
	int m_height;

	GLint projUniform;
	GLint shaderProgramID;

	SDL_Window* m_window;
	SDL_GLContext m_context;

};
typedef Singleton<ScreenManager> Screen;