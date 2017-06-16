#include "InputManager.h"
#include "ObjectsManager.h"
#include <iostream>
#include <SDL.h>
#include <string>
#include <iostream>
#include <SDL.h>
#include <string>
#include <vector>
#include <glew.h>
#include <windows.h>
#include <glm.hpp>
#include <glext.h>
#include <math.h>

SDL_Event events;

int key;
InputManager::InputManager()
{
}

const Uint8 * InputManager::GetKeyStates()
{

	return m_keystates;
}

bool InputManager::IsXClicked()
{

	return m_isXclicked;
}

bool InputManager::IsUpPressed()
{
	return m_UpKey;
}

bool InputManager::IsDownPressed()
{
	return m_DownKey;
}

bool InputManager::IsRightPressed()
{
	
	return m_RightKey;
}

bool InputManager::IsLeftPressed()
{
	return m_LeftKey;
}

bool InputManager::IsPPressed()
{
	return m_P;
}

bool InputManager::IsReturnPressed()
{
	return m_Return;
}

bool InputManager::IsWPressed()
{
	return m_WKey;
}

bool InputManager::IsSPressed()
{
	return m_SKey;
}

bool InputManager::IsAPressed()
{
	
	return m_AKey;
}

bool InputManager::IsDPressed()
{
	return m_DKey;
}

bool InputManager::IsPlusPressed()
{
	return m_PlusKey;
}

bool InputManager::IsMinusPressed()
{
	return m_MinusKey;
}

void InputManager::Update()
{

	m_keystates = SDL_GetKeyboardState(0);



	while (SDL_PollEvent(&events)) {
			
			m_mousemotion.x = 0;
			m_mousemotion.y = 0;

		switch (events.type) {

		case SDL_QUIT:
			m_isXclicked = true;
			break;


		case SDL_MOUSEMOTION:
			m_mousemotion.x = events.motion.xrel;
			m_mousemotion.y = events.motion.yrel;

			break;

		case SDL_MOUSEWHEEL:
			m_mousewheel.x = events.wheel.x;
			m_mousewheel.y = events.wheel.y;

			break;
	
		case SDL_MOUSEBUTTONDOWN:
			m_isMousePressed = true;
			break;
			
		case SDL_MOUSEBUTTONUP:
			m_isMousePressed = false;
			break;


		}

	}

	if (m_keystates[SDL_SCANCODE_ESCAPE])
	{
		m_isXclicked = true;
	}
	else
	{
		m_isXclicked = false;
	}

	if (m_keystates[SDL_SCANCODE_P] == 1)
			{
				m_P = true;
			}
	else { m_P = false; }
	

	if (m_keystates[SDL_SCANCODE_RETURN] == 1)
			{
				m_Return = true;
			}
	else { m_Return = false; }
	
	/***********************************************************/

	if (m_keystates[SDL_SCANCODE_RIGHT] == 1)
			{
				m_RightKey = true;
			}
	else { m_RightKey = false; }
	
	if (m_keystates[SDL_SCANCODE_LEFT] == 1)
			{
				m_LeftKey = true;
			}
	else { m_LeftKey = false; }
	/**********************************************************/

	if (m_keystates[SDL_SCANCODE_UP] == 1)
			{
				m_UpKey = true;
			}
	else { m_UpKey = false; }
	
	if (m_keystates[SDL_SCANCODE_DOWN] == 1)
			{
				m_DownKey = true;
			}
	else { m_DownKey = false; }
	

	/******************************************************/

	if (m_keystates[SDL_SCANCODE_W] == 1)
			{
				m_WKey = true;
			}
	else { m_WKey = false; }


	
	if (m_keystates[SDL_SCANCODE_S] == 1)
			{
				m_SKey = true;
			}
	else { m_SKey = false; }


	if (m_keystates[SDL_SCANCODE_A] == 1)
			{
				m_AKey = true;
			}
	else { m_AKey = false; }


	
	if (m_keystates[SDL_SCANCODE_D] == 1)
			{
				m_DKey = true;
			}
	else { m_DKey = false; }



	/*********************************************/

	if (m_keystates[SDL_SCANCODE_KP_PLUS] == 1)
			{
				m_PlusKey = true;
			}
	else { m_PlusKey = false; }


	
	if (m_keystates[SDL_SCANCODE_KP_MINUS] == 1)
			{
				m_MinusKey = true;
			}
	else { m_MinusKey = false; }

	//SDL_SetRelativeMouseMode(SDL_TRUE);

}

glm::vec2 InputManager::MousePos()
{
	
	return 	m_mouseposition;
}

glm::vec2 InputManager::MouseMov()
{
	return m_mousemovement;
	
}

bool InputManager::MousePresed()
{
	return m_isMousePressed;
}

glm::vec2 InputManager::MouseWheel()
{
	return m_mousewheel;
}

glm::vec2 InputManager::MouseSpeed()
{
	return m_mousemotion;
}

