#include "HighScoreState.h"
#include "DebugManager.h"
#include "ScreenManager.h"
#include "MainMenuState.h"
#include "Game.h"



HighScoreState::HighScoreState(Gamestates* current):Gamestates(current)
{
	_isActive = _isAlive = true;
	Initialise();
}

bool HighScoreState::Initialise()
{
	_hg.Initialise();
	two_d_cam.Locate();

	two_d_cam.Initialise();

	Debug::Instance()->CHECK(_btn_BACK_TO_MENU.Initialise(150, 150, -1, 150, 150, "MENU"), "Button 1 initialisation");
	Debug::Instance()->CHECK(_btn_PLAY.Initialise(WIDTH - 150, 150, -1, 150, 150, "PLAY"), "Button 2 initialisation");

	Screen::Instance()->TwoDScreen(WIDTH, HEIGHT);

	//
	//for (int i = 0; i < 10; i++)
	//{
	//	_score = _score + std::to_string(i+1)+": " + std::to_string(_hg.GetHighscore()[i]).substr(0,3) + ">";
	//}
	
	for (int i = 0; i < 10; i++)
	{
		std::string _score = "";

		_score = std::to_string(i+1)+": " + std::to_string(_hg.GetHighscore()[i]);

		_label[i].Write(600, 750 - i*50,-1,75,50, _score);
	}


	//_label.Write(600, 750, -1,75,50,_score,10);

	return true;
}

void HighScoreState::Update(double dt)
{
	_btn_BACK_TO_MENU.Update(dt);
	_btn_PLAY.Update(dt);

	if (_btn_BACK_TO_MENU.IsClicked())
	{
		TheGame::Instance()->ChangeState(new MainMenuState(this)); 
		_isActive = false;
		_isAlive = false;	
	}


	if (_btn_PLAY.IsClicked())
	{
		TheGame::Instance()->ChangeState(new RunState(this));
		
		_isActive = false;
		_isAlive = false;
	}

	two_d_cam.Update();
}

void HighScoreState::Draw()
{

	two_d_cam.Draw();
	
	//_label.Draw();
	for (int i = 0; i < 10; i++)
	{
		_label[i].Draw();
	}
	_btn_BACK_TO_MENU.Draw();
	_btn_PLAY.Draw();
}


HighScoreState::~HighScoreState()
{

}
