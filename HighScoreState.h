#pragma once
#include "Gamestates.h"
#include "Buttons.h"
#include"Text.h"
#include"TwoDCam.h"
#include"HighScore.h"

class HighScoreState :
	public Gamestates
{
public:
	HighScoreState(Gamestates * current);

	bool Initialise();

	void Update(double dt);

	void Draw();



	TwoDCam two_d_cam;
	Text _label[10];

	HighScore _hg;

	std::string _player_winner;

	Buttons _btn_BACK_TO_MENU;
	Buttons _btn_PLAY;



	virtual ~HighScoreState();
};

