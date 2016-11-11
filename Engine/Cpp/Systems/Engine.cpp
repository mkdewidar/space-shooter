#include "Engine.h"


Engine::Engine()
	: gameObjects(),
	gameState(this->gameObjects),
	objectManager(this->gameObjects),
	logicManager(this->gameObjects),
	physics(this->gameObjects),
	renderer(this->gameObjects)
{
	this->gameState.SetupSystem(&this->messageBus);

	this->objectManager.SetupSystem(&this->messageBus);

	this->logicManager.SetupSystem(&this->messageBus);

	this->physics.SetupSystem(&this->messageBus);

	this->renderer.SetupSystem(&this->messageBus);

	this->messageBus.SetupSystem( { &this->gameState, &this->objectManager, 
		&this->logicManager, &this->physics, &this->renderer } );

	CreateObjectMsg createPlayerMsg = CreateObjectMsg(GameObjectTypes::PLAYER);
	this->messageBus.PostMessage(&createPlayerMsg);
	size_t noOfAsteroids = 10/*rand() % 10 + 1*/;
	for (size_t counter = 0; counter < noOfAsteroids; counter++)
	{
		CreateObjectMsg createAsteroidMsg = CreateObjectMsg(GameObjectTypes::ASTEROID);
		this->messageBus.PostMessage(&createAsteroidMsg);
	}
}

Engine::~Engine()
{
	for (size_t index = 0; index < this->gameObjects.Capacity(); index++)
	{
		delete this->gameObjects[index];
	}

	SDL_Quit();
}

void Engine::RunScene()
{
	// if it's not over yet keep going!
	while (!this->gameState.IsItOver())
	{
		double deltaTime = this->time.GetDeltaTime() / 1000.0;
		this->time.ResetTime();

		this->gameState.Update(deltaTime);
		this->objectManager.Update(deltaTime);
		this->logicManager.Update(deltaTime);
		this->physics.Update(deltaTime);
		this->renderer.Update(deltaTime);
	}
}
