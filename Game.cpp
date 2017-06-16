#include <iostream>
#include <SDL.h>
#include <string>
#include <vector>
#include <glew.h>
#include <glm.hpp>

#include "ScreenManager.h"
#include "MeshLoader.h"
#include "InputManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "ObjectsManager.h"
#include "ThirdPerson.h"
#include "DebugManager.h"
#include "Game.h"




bool Game::Initialise(std::string GameName, int Width, int Height)
{
	//Screen::Instance()->SetBackgroundColor(1, 0, 0);

	if (!Screen::Instance()->Init(GameName, Width, Height, 3, 3, false, true)) //Create a gl context and window with assignable parameters
	{
		std::cout << "Screen not initialised" << std::endl;
		return false;
	}
	
	Texture::Instance()->LoadFile("Media/Textures/HUD_2.png", "HUD");
	Texture::Instance()->LoadFile("Media/Textures/hud_neon.png", "NEON_HUD");

	Texture::Instance()->LoadFile("Media/Font/Calibri.png", "CALIBRI");
	Texture::Instance()->LoadFile("Media/Textures/normal.png", "BUTTON_NSTATE");
	Texture::Instance()->LoadFile("Media/Textures/clicked.png", "BUTTON_CLICKEDSTATE");

	Debug::Instance()->CHECK(Shade::Instance()->CreateProgram(), "Creating the shader program");
	Debug::Instance()->CHECK(Shade::Instance()->CreateShaders(), "Creating the shader");

	Debug::Instance()->CHECK(Shade::Instance()->AttachShaders(), "Attaching the shader");
	Debug::Instance()->CHECK(Shade::Instance()->CompileShaders("Main.vert"), "Compiling vertex shaders file");
	Debug::Instance()->CHECK(Shade::Instance()->CompileShaders("Main.frag"), "Compiling fragment shaders file");

	Debug::Instance()->CHECK(Shade::Instance()->LinkProgram(), "Linking the programs");

	
	Debug::Instance()->CHECK(Audio::Instance()->Init(), "Audio initialisation");
	Debug::Instance()->CHECK(Audio::Instance()->LoadMusic("soundtrack.mp3"), "Audio loading");

		
	m_Gstates.push_back(new MainMenuState(nullptr));
	
	std::cout << "Initialisation of Game succeded" << std::endl;
	return true;
}

void Game::Run()
{
	
		while (!endGame) //GAME LOOP
		{
			NOW = SDL_GetTicks();
			
			if (m_Gstates.front()->isAlive())
			{

				Screen::Instance()->clearScreen();
				Audio::Instance()->Update();
				Input::Instance()->Update();


				m_Gstates.front()->Update(DeltaTime);
				m_Gstates.front()->Draw();



				Screen::Instance()->SwapBuffer();

			}

			if (Input::Instance()->IsXClicked())
			{
				endGame = true;
			}

				if (!m_Gstates.front()->isAlive())
			{
 				DeleteState();
			}

			if (m_Gstates.empty()) //if everything is deleted exit
			{
				endGame = true;
			}
			LAST = SDL_GetTicks();
			DeltaTime = (LAST - NOW) / 1000;
			LAST = NOW = 0;


		
		}

		for (size_t i = 0; i < m_Gstates.size(); i++)
		{
			delete m_Gstates[i];
		}

		m_Gstates.clear();
	
}

void Game::AddTempState(Gamestates * my_state)
{
	m_Gstates.push_front(my_state);
}

void Game::ChangeState(Gamestates * my_state)
{
	m_Gstates.push_back(my_state);

	m_Gstates.front()->isActive() = false;
	m_Gstates.front()->isAlive() = false;
}

void Game::DeleteState()
{
	delete m_Gstates.front();
	m_Gstates.pop_front();
}


void Game::ShutDown()
{
	
	Shade::Instance()->DetachDestroy();
	Texture::Instance()->UnloadFile();
	Screen::Instance()->ShutDown();
	Audio::Instance()->Unload();
	Audio::Instance()->ShutDown();

}


//
//void Game::CheckInput()
//{
//
//
//
//	if (Input::Instance()->IsXClicked())
//	{
//		endGame = true;	
//	}
//
//	
//	if (Input::Instance()->IsMinusPressed())
//	{
//		p -= 0.001;	
//	}
//	
//	if (Input::Instance()->IsPlusPressed())
//	{
//		p += 0.001;	
//	}
//	
//
//}

Game::Game()
{
}


