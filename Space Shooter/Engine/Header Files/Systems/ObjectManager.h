#pragma once

#include "System.h"
#include "SlotMap.h"

/*
Defines a class that manages all the objects in the game engine
*/
class ObjectManager 
	: public System
{
public:
	ObjectManager(SlotMap<GameObject*> gameObjs);
	~ObjectManager();

	void Update(double dTime) override;

	void HandleMessage(Msg* postedMsg) override;

private:
	// all the game objects in the scene
	SlotMap<GameObject*>& gameObjects;
};

