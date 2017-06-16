#pragma once
#include "Gamestates.h"
#include "Buttons.h"
#include "TwoDCam.h"

class PauseState :
	public Gamestates
{
public:
	PauseState(Gamestates *current);


	bool Initialise();
	void Update(double dt);
	void Draw();
	
	Buttons _btn_PLAY;
	Buttons _btn_QUIT;
	Buttons _btn_MAIN_MENU;

	TwoDCam _two_d_cam;

	virtual ~PauseState();
};

