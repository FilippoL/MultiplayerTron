#include "PauseState.h"
#include "DebugManager.h"
#include "ScreenManager.h"
#include "Game.h"
#include "MainMenuState.h"
#include "RunState.h"



PauseState::PauseState(Gamestates* current) : Gamestates(current)
{	
	std::cout << "PAUSE STATE" << std::endl;

	_isActive = _isAlive = true;

	Initialise();

}

bool PauseState::Initialise()
{
	Debug::Instance()->CHECK(_btn_PLAY.Initialise(450, 500, -1, 250, 250, "RESUME"), "Button 1 initialisation");
	Debug::Instance()->CHECK(_btn_QUIT.Initialise(750, 500, -1, 250, 250, "EXIT"), "Button 2 initialisation");
	Debug::Instance()->CHECK(_btn_MAIN_MENU.Initialise(600, 250, -1, 250, 250, "MAIN MENU"), "Button 3 initialisation");


	_two_d_cam.Locate();
			 
	_two_d_cam.Initialise();

	return false;
}

void PauseState::Update(double dt)
{
	_two_d_cam.Update();

	_btn_PLAY.Update(dt);
	_btn_QUIT.Update(dt);
	_btn_MAIN_MENU.Update(dt);
	

	if (_btn_PLAY.IsClicked()) {
		
		_StatePrevious->isActive() = true;
		_StatePrevious->isAlive() = true;

		_isActive = false;
		_isAlive = false;
		

	}

	if (_btn_QUIT.IsClicked()) {

		_StatePrevious->isActive() = false;
		_StatePrevious->isAlive() = false;

		_isActive = false;
		_isAlive = false;
	}


	if (_btn_MAIN_MENU.IsClicked()) {
	
		TheGame::Instance()->ChangeState(new MainMenuState(this)); 

		_StatePrevious->isActive() = false;
		_StatePrevious->isAlive() = false;

		_isActive = false;
		_isAlive = false;
	}

}

void PauseState::Draw()
{
	Screen::Instance()->TwoDScreen(WIDTH, HEIGHT);
	glViewport(0.0,0.0,WIDTH, HEIGHT);

	_two_d_cam.Draw();

	_btn_MAIN_MENU.Draw();
	_btn_PLAY.Draw();
	_btn_QUIT.Draw();

}


PauseState::~PauseState()
{

}
