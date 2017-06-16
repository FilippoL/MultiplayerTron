#pragma once
#include "Singleton.h"
#include "RunState.h"
#include "MainMenuState.h"
#include "Gamestates.h"
#include "ScreenManager.h"

#include "InputManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "ObjectsManager.h"

#include "AudioComponent.h"

#include <iostream>
#include <SDL.h>
#include <string>
#include <vector>
#include <glew.h>
#include <glm.hpp>
#include <fmod.hpp>
#include <iostream>
#include <deque>


class Game
{

public:

	friend class Singleton<Game>;

	bool Initialise(std::string GameName, int Width, int Height);
	void Run() ;
	void AddTempState(Gamestates * my_state);
	void ChangeState(Gamestates * my_state);
	void DeleteState();
	void ShutDown() ;
	
	bool endGame;

private:
	double NOW, DeltaTime, LAST;

private:

	Game();
	Game(const Game&);


	Game& operator=(const Game&);

private:
	bool isRunning = true;

	Gamestates* m_state;
	std::deque<Gamestates*> m_Gstates;



};

typedef Singleton<Game> TheGame;


