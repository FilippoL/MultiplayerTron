#pragma once
#include "MeshLoader.h"
#include "InputManager.h"
#include "BoostBar.h"

#define FIELD_SIZE 1000
#define MAX_BOOST_SPEED 7.5
#define MAX_SPEED 4.5
#define INITIAL_SPEED 2.5

class Player :
	public MeshLoader
{
public:

	Player(bool isPlayer2 = false);


	bool Initialise(const char * Obj, std::string texture);
	
	void Update(double dt);

	void StartRun();
	void EndRun();

	glm::vec3 GetRotation();

	void Draw();
	BoostBar _boost_bar;

	void CreateScreenPointer(glm::vec3 pos);

	glm::vec3 GetPosition();
	void CheckInput();
	bool goingdown;
	void SetBarPosition(float x, float y, float z);
	void DrawBoostBar();
	virtual ~Player();

private:
	void InitialiseMaterial();
	float boost;
	float Speed;
	float boost_speed;
	bool isAlive;
	bool _second_p;
	glm::vec3 position;
	

	float inclination_angle;
	float curve_angle;

	float inclination_up_angle;
	float curve_up_angle;


};

