#include "RunState.h"
#include "Light.h"
#include "DebugManager.h"
#include "Floor.h"
#include "Game.h"
#include "GameOverState.h"
#include "PauseState.h"

RunState::RunState(Gamestates* current) : Gamestates(current)
{
	std::cout << "RUN STATE" << std::endl;
	
	_isActive = _isAlive = true;

	player_1 = new Player;
	player_2 = new Player(true);

	_cam_player_1 = new ThirdPerson;
	_cam_player_2 = new ThirdPerson;

	_two_d_cam = new TwoDCam;

	flooring = new Floor;
	light = new Light;
	music = new AudioComponent;
	

	Initialise();
}


bool RunState::Initialise()
{
	timer = 0;

	_fbo.Initialise();

	Texture::Instance()->AddTexture("FBO", _fbo.GetTexture());

	Debug::Instance()->CHECK(_player_one_hud.Initialise(WIDTH / 2, HEIGHT / 8, -1, 900, 35), "HUD p1 initialisation");
	Debug::Instance()->CHECK(_player_two_hud.Initialise(WIDTH / 2, HEIGHT / 8, -1, 900, 35), "HUD p2 initialisation");


	Debug::Instance()->CHECK(_hud.Initialise(WIDTH/2,HEIGHT/2,-1,WIDTH, HEIGHT), "HUD initialisation");

	Debug::Instance()->CHECK(player_1->Initialise( "Media/FlyingCar/Flying_Car_lowpol.obj",//obj
												"Media/Textures/Cube1.jpg"),//texture
												"OBJ player1 Initialisation");//alert

	Debug::Instance()->CHECK(player_2->Initialise( "Media/FlyingCar/Flying_Car_lowpol.obj",//obj
												"Media/Textures/Cube1.jpg"),//texture
												"OBJ player2 Initialisation");//alert

	Debug::Instance()->CHECK(flooring->Initialise(0, 0, 0, 2000, 2000), "Flooring initialisation");

	Debug::Instance()->CHECK(_wake.Initialise(), "Wake initialisation");

	Debug::Instance()->CHECK(_wake_2.Initialise(), "Wake initialisation");
		
	Debug::Instance()->CHECK(_screen.Initialise(WIDTH/2,HEIGHT/2,-2,WIDTH, HEIGHT), "Screen FBO");
	
	Debug::Instance()->CHECK(_enviroment.Initialise("Media/skydome.obj","Media/Textures/cube2.jpg"), "Enviroment initialisation");
	
	Debug::Instance()->CHECK(light->Initalise(), "Light initialisation");

	player_1->SetBarPosition(WIDTH / 6, 100, -1);
	player_2->SetBarPosition(WIDTH / 6, 100, -1);


	_cam_player_1->Locate();
	_cam_player_1->Initialise();

	_cam_player_2->Locate();
	_cam_player_2->Initialise();

	_two_d_cam->Locate();
	_two_d_cam->Initialise();
		
	_txt_p1.Write(WIDTH/2,HEIGHT/12,-2,50,25,"PLAYER ONE (A W D)>TO BOOST WAIT THE BAR IS FULL",2);


	_txt_p2.Write(WIDTH/2, HEIGHT/12, -2, 50, 25, "PLAYER TWO (ARROWS)>TO BOOST WAIT THE BAR IS FULL",2);


	music->SetMusic();
	music->Play();

	
	return true;
}

void RunState::Update(double dt)
{
	timer += dt;

	
	light->Update();
	light->SetPositon(glm::vec3(0.0,50.0,0.0));

	_cam_player_1->Update(dt, player_1->GetRotation());
	_cam_player_1->SetTarget(player_1->GetPosition());

	_cam_player_2->Update(dt, player_2->GetRotation());
	_cam_player_2->SetTarget(player_2->GetPosition());

	_two_d_cam->Update();

	_enviroment.Spin(dt);

	player_1->Update(dt);
	player_2->Update(dt);
	
	flooring->Update(dt);

	


	if (_wake_2.CollisionHappening(player_1->GetPosition()) && _isActive && _isAlive )
	{

		TheGame::Instance()->ChangeState(new GameOverState(this, true, timer));//, true, timer));
		
		_isActive = false;
		_isAlive = false;
	}

	if (_wake.CollisionHappening(player_2->GetPosition()) && _isActive && _isAlive)
	{
		TheGame::Instance()->ChangeState(new GameOverState(this, false, timer));

		_isActive = false;
		_isAlive = false;

	}



	if (Input::Instance()->IsPPressed())
	{
		TheGame::Instance()->AddTempState(new PauseState(this));
		_isActive = false;
		_isAlive = true;
	}

}

void RunState::Draw()
{
	_fbo.BindFBO();

	Screen::Instance()->clearScreen();



	Screen::Instance()->ThreeDScreen(135.0f, WIDTH, HEIGHT);

	glViewport(0.0,0.0,WIDTH/2, HEIGHT);

	_cam_player_1->Draw();

	light->Draw();
	
	player_2->Draw();
	player_1->Draw();


	flooring->Draw("TILES");
	_wake.Update(player_1->GetPosition(), player_1->GetRotation());
	_wake_2.Update(player_2->GetPosition(), player_2->GetRotation());

	/***********************************************************/
	glViewport(WIDTH / 2, 0.0, WIDTH / 2, HEIGHT);


	

	_cam_player_2->Draw();
	//_enviroment.Draw();



	player_2->Draw();
	player_1->Draw();
	

	flooring->Draw("TILES");


	_wake.Update(player_1->GetPosition(),player_1->GetRotation());
	_wake_2.Update(player_2->GetPosition(), player_2->GetRotation());
	

	_fbo.UnBindFBO();	
	
	Screen::Instance()->clearScreen();

	
	Screen::Instance()->TwoDScreen(WIDTH, HEIGHT);//2d scene
	glViewport(0.0, 0.0, WIDTH, HEIGHT);
	_two_d_cam->Draw(); //2d cam

	
	_screen.Draw(_fbo.GetTexture()); //render the fbo

	/****************SPLIT SCREENS HUD***********************/
	_hud.Draw("HUD");

	/***********UI FOR PLAYER ONE**************/
	glViewport(0.0, 0.0, WIDTH/2, HEIGHT);
	player_1->DrawBoostBar();
	_player_one_hud.Draw("NEON_HUD");
	_txt_p1.Draw();

	/***********UI FOR PLAYER TWO**************/
	glViewport(WIDTH/2, 0.0, WIDTH/2, HEIGHT);
	player_2->DrawBoostBar();
	_player_two_hud.Draw("NEON_HUD");
	_txt_p2.Draw();

	glViewport(0.0, 0.0, WIDTH, HEIGHT);


	//Screen::Instance()->clearScreen();
}

RunState::~RunState()
{
//	_fbo.Delete();
	
	
	delete player_2;
	delete player_1;
	delete _two_d_cam;
	delete music;
	delete light;
	delete flooring;
	delete _cam_player_1;
	delete _cam_player_2;


}
