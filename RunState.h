#pragma once
#include "Gamestates.h"

#include "ScreenManager.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "ObjectsManager.h"
#include "FrameBufObject.h"
#include "Text.h"
#include "HUD.h"
#include "Sprite.h"
#include "Player.h"
#include "ThirdPerson.h"
#include "AudioComponent.h"
#include "Light.h"
#include "Floor.h"
#include "SkyDome.h"
#include "TwoDCam.h"
#include "Wake.h"
#include "Screen_pannel.h"
#include "Buttons.h"

class RunState :
	public Gamestates
{
public:
	RunState(Gamestates * current);
	virtual ~RunState();

	bool Initialise();
	void Update(double dt);
	void Draw();

public:
	std::vector<glm::vec3> cubePositions;

private:

	Floor* flooring;
	Player* player_1;
	Player* player_2;

	FrameBufObject _fbo;

	Screen_pannel _screen;

	ThirdPerson* _cam_player_1;
	ThirdPerson* _cam_player_2;

	TwoDCam* _two_d_cam;

	HUD _hud;

	HUD _player_one_hud;
	HUD _player_two_hud;


	Text _txt_p1;
	Text _txt_p2;


	Wake _wake;
	Wake _wake_2;

	float timer;
	AudioComponent* music;
	Light* light;
	SkyDome _enviroment;
	

};

