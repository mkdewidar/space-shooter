#pragma once

#include <SDL.h>
#include "TimeManager.h"
#include "GameState.h"
#include "ObjectManager.h"
#include "LogicManager.h"
#include "Physics.h"
#include "Renderer.h"


/*
The game engine that runs the game
*/
class Engine
{
public:
	Engine();
	~Engine();

	/*
	Main functionality of the scene, contains main loop
	*/
	void RunScene();

private:
	// object that allows time capabilities
	TimeManager time;

	// vector of all the game objects in the scene
	vector<GameObject*> gameObjects;

	MessageBus messageBus;
	GameState gameState;
	ObjectManager objectManager;
	LogicManager logicManager;
	Physics physics;
	Renderer renderer;
};

