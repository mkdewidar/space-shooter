#pragma once

#include "System.h"

/*
Defines the system that manages all the physics of the game
*/
class Physics
	: public System
{
public:
	Physics(SlotMap<GameObject*>& gameObjs);
	~Physics();

	void Update(double dTime) override;

	void HandleMessage(Msg* postedMsg) override;

private:
	// the slot map of all game objects in the game
	const SlotMap<GameObject*>& gameObjects;
};

