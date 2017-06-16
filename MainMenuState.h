#pragma once
#include "Gamestates.h"
#include "Buttons.h"
#include "TwoDCam.h"

class MainMenuState :
	public Gamestates
{
public:
	MainMenuState(Gamestates *current);
	virtual ~MainMenuState();
	bool Initialise();
	void Update(double dt);
	void Draw();

	Buttons _btn_PLAY;
	Buttons _btn_QUIT;
	Buttons _btn_CREDITS;
	Buttons _btn_HIGHSCORE;

	TwoDCam two_d_cam;

};

