#pragma once

#include "System.h"

/*
Defines the system that manages the drawing to the screen
*/
class Renderer
	: public System
{
public:
	Renderer(vector<GameObject*>* gameObjects, MessageBus* messageBus);
	~Renderer();

	void Update(double dTime) override;

	void HandleMessage(Msg* msg) override;
};

