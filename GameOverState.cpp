#include "GameOverState.h"
#include "DebugManager.h"
#include "Game.h"
#include "HighScoreState.h"
//#include "Highscore"


GameOverState::GameOverState(Gamestates * current, bool isFirst, float _score) : Gamestates(current)
{
	_isActive = _isAlive = true;
	__score = _score;
	_first_player_won = isFirst;
	Initialise();
}

bool GameOverState::Initialise()
{
	_hg.Initialise();

	Debug::Instance()->CHECK(_btn_SUBMIT.Initialise(200, 150, -1, 150, 150, "SUBMIT"), "Button 1 initialisation");
	Debug::Instance()->CHECK(_btn_QUIT.Initialise(1000, 150, -1, 150, 150, "MAIN>MENU",2), "Button 2 initialisation");
		
	_first_player_won ? _player_winner = "PLAYER ONE WON" : _player_winner = "PLAYER TWO WON";

	const char* name;
	name = _player_winner.c_str();

	_name.Write(600, 250, -1, 75, 75, name);

	std::string points;


	if (__score < _hg.GetHighscore()[ 0])
	{
		points = ("!! NEW HIGHSCORE !! > YOU DEFEATED YOUR OPONENT IN: " + std::to_string(__score) + "s");
		_label.Write(600, 450, -1, 25, 25, points , 2);
	}

	else
	{
		points = "YOU DEFEATED YOUR OPONENT IN: " + std::to_string(__score) + "s";
		_label.Write(600, 450, -1, 30, 30, points);
	}
	

	two_d_cam.Locate();
			 
	two_d_cam.Initialise();
	return true;
	
}
void GameOverState::Update(double dt)
{
		two_d_cam.Update();
		_btn_QUIT.Update(dt);
		_btn_SUBMIT.Update(dt);

	if (_btn_SUBMIT.IsClicked()) {

		_hg.UpdateHighscore(__score);

		TheGame::Instance()->ChangeState(new HighScoreState(this)); //menu state ususally happens to be the first
	
		_isActive = false;
		_isAlive = false;	

	}

	if (_btn_QUIT.IsClicked()) {

		TheGame::Instance()->ChangeState(new MainMenuState(this));

			(_StatePrevious)?_StatePrevious->isActive() = false : 0;
		(_StatePrevious)?_StatePrevious->isAlive() = false : 0;

		_isActive = false;
		_isAlive = false;
	}

}

void GameOverState::Draw()
{
	Screen::Instance()->TwoDScreen(WIDTH, HEIGHT);

	two_d_cam.Draw();
	_label.Draw();
	_name.Draw();
	_btn_SUBMIT.Draw();
	_btn_QUIT.Draw();
}

GameOverState::~GameOverState()
{
	
}
