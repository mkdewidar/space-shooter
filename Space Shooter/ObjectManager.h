#pragma once

#include "System.h"

/*
Defines a class that manages all the objects in the game engine
*/
class ObjectManager 
	: public System
{
public:
	ObjectManager(vector<GameObject*>* gameObjects, MessageBus* messageBus);
	~ObjectManager();

	void Update(double dTime) override;

	void HandleMessage(Msg* msg) override;
};

