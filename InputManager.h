#pragma once
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
#include "Singleton.h"


class InputManager
{
public:
	friend class Singleton<InputManager>;

	const Uint8* GetKeyStates();

	bool IsXClicked();

	bool IsUpPressed();
	bool IsDownPressed();
	bool IsRightPressed();
	bool IsLeftPressed();

	bool IsPPressed();
	bool IsReturnPressed();


	bool IsWPressed();
	bool IsSPressed();
	bool IsAPressed();
	bool IsDPressed();

	bool IsPlusPressed();
	bool IsMinusPressed();



	void Update();

	glm::vec2 MousePos();

	glm::vec2 MouseMov();

	bool MousePresed();

	glm::vec2 MouseWheel();

	glm::vec2 MouseSpeed();

	
public:

	InputManager();
	InputManager(const InputManager&);
	InputManager& operator=(const InputManager&);

	bool m_isXclicked;
	bool m_isKeypressed;
	bool m_isMousePressed;

	glm::vec2 m_mousemotion;
	glm::vec2 m_mousewheel;
	glm::vec2 m_mouseposition;
	glm::vec2 m_mousemovement;

	const Uint8* m_keystates;


	bool m_UpKey;
	bool m_DownKey;
	bool m_RightKey;
	bool m_LeftKey;
	bool m_P;
	bool m_Return;

	bool m_WKey;
	bool m_SKey;
	bool m_AKey;
	bool m_DKey;

	bool m_PlusKey;
	bool m_MinusKey;
	

};

typedef Singleton<InputManager> Input;