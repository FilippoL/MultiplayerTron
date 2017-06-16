#pragma once
#include <iostream>

class Gamestates
{
public:
	Gamestates(Gamestates * current_state)  { 	_StatePrevious = current_state;
													std::cout << "You are in state: "; };
	virtual ~Gamestates() = 0 {};

public:
	virtual bool Initialise() = 0 { return true; };
	virtual void Update(double dt) = 0 {};
	virtual void Draw() = 0 {};

protected:
	bool _isAlive;
	bool _isActive;

public:
	Gamestates* _StatePrevious;
public:
	bool &isAlive(){	return _isAlive; };
	bool &isActive(){	return _isActive; };

};

