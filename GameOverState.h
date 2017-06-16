#pragma once
#include "Gamestates.h"
#include "Buttons.h"
#include "TwoDCam.h"
#include "Text.h"
#include "HighScore.h"

class GameOverState :
	public Gamestates
{
public:
	GameOverState(Gamestates * current, bool isFirst, float _score);
	bool Initialise();

	void Update(double dt);

	void Draw();

	float __score;
	bool _first_player_won;
	virtual ~GameOverState();

	TwoDCam two_d_cam;
	Text _label;
	Text _name;

	HighScore _hg;

	std::string _player_winner;


	Buttons _btn_QUIT;
	Buttons _btn_SUBMIT;
};

