#include "MainMenuState.h"
#include "InputManager.h"
#include "Game.h"
#include "RunState.h"
#include "DebugManager.h"
#include "HighScoreState.h"

MainMenuState::MainMenuState(Gamestates *current): Gamestates(current)
{
	_isActive = _isAlive = true;
	Initialise();
}


MainMenuState::~MainMenuState()
{
	
}

bool MainMenuState::Initialise()
{
	Debug::Instance()->CHECK(_btn_PLAY.Initialise(800, 250, -1, 250, 250, "PLAY"), "Button 1 initialisation");
	Debug::Instance()->CHECK(_btn_QUIT.Initialise(400, 500, -1, 250, 250, "EXIT"), "Button 2 initialisation");
	Debug::Instance()->CHECK(_btn_HIGHSCORE.Initialise(800, 500, -1, 250, 250, "HIGHSCORE"), "Button 3 initialisation");
	Debug::Instance()->CHECK(_btn_CREDITS.Initialise(400, 250, -1, 250, 250, "CREDITS"), "Button 4 initialisation");

	Screen::Instance()->TwoDScreen(WIDTH, HEIGHT);

	two_d_cam.Locate();
			 
	two_d_cam.Initialise();


	return false;
}

void MainMenuState::Update(double dt)
{
	two_d_cam.Update();

	_btn_PLAY.Update(dt);
	_btn_QUIT.Update(dt);
	_btn_HIGHSCORE.Update(dt);
	_btn_CREDITS.Update(dt);


	if (_btn_PLAY.IsClicked()) {

		TheGame::Instance()->ChangeState(new RunState(this));
		
		_isActive = false;
		_isAlive = false;

	}

	if (_btn_QUIT.IsClicked()) {

		_isActive = false;
		_isAlive = false;
	}


	if (_btn_HIGHSCORE.IsClicked()) {
	
		TheGame::Instance()->ChangeState(new HighScoreState(this)); 

		_isActive = _isAlive = false;
	}

	if (_btn_CREDITS.IsClicked()) {
	
		
	}

}

void MainMenuState::Draw()
{
	two_d_cam.Draw();

	_btn_HIGHSCORE.Draw();
	_btn_PLAY.Draw();
	_btn_QUIT.Draw();
	_btn_CREDITS.Draw();


}
