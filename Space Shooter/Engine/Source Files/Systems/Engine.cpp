#include "../../Header Files/Systems/Engine.h"


Engine::Engine()
{
	this->gameState.SetupMsgBusReferences(&this->messageBus, &this->gameObjects);

	this->objectManager.SetupMsgBusReferences(&this->messageBus, &this->gameObjects);

	this->logicManager.SetupMsgBusReferences(&this->messageBus, &this->gameObjects);

	this->physics.SetupMsgBusReferences(&this->messageBus, &this->gameObjects);

	this->renderer.SetupMsgBusReferences(&this->messageBus, &this->gameObjects);

	this->messageBus.SetupMsgBusReferences( { &this->gameState, &this->objectManager, 
		&this->logicManager, &this->physics, &this->renderer } );

	CreateObjectMsg msg;
	this->messageBus.PostMessage(&msg);
}

Engine::~Engine()
{
	for (GameObject* object : this->gameObjects)
	{
		delete object;
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

		this->logicManager.Update(deltaTime);
		this->physics.Update(deltaTime);
		this->renderer.Update(deltaTime);
	}
}
