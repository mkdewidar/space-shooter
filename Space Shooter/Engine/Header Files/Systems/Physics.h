#pragma once

#include "System.h"

/*
Defines the system that manages all the physics of the game
*/
class Physics
	: public System
{
public:
	Physics();
	~Physics();

	void Update(double dTime) override;

	void HandleMessage(Msg* postedMsg) override;
};
