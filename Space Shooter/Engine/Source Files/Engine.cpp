#include "../Header Files/Engine.h"


Engine::Engine()
{
	this->time = TimeManager();

	this->messageBus = MessageBus();

	this->objectManager = ObjectManager();
	this->objectManager.SetupMsgBusReferences(&this->messageBus, &this->gameObjects);

	this->logicManager = LogicManager();
	this->logicManager.SetupMsgBusReferences(&this->messageBus, &this->gameObjects);

	this->physics = Physics();
	this->physics.SetupMsgBusReferences(&this->messageBus, &this->gameObjects);

	this->renderer = Renderer();
	this->renderer.SetupMsgBusReferences(&this->messageBus, &this->gameObjects);

	this->messageBus.SetupMsgBusReferences( { &this->objectManager, &this->logicManager,
		&this->physics, &this->renderer } );
}

Engine::~Engine()
{
	for (GameObject* object : this->gameObjects)
	{
		delete object;
	}
}

void Engine::RunScene()
{


	/*while (this->currentSceneState != SceneState::QUIT)
	{
		double deltaTime = this->time.GetDeltaTime() / 1000.0;
		this->time.ResetTime();

		while (SDL_PollEvent(&this->e) != 0)
		{
			if (this->e.type == SDL_KEYDOWN)
			{
				if (this->e.key.keysym.sym == SDLK_ESCAPE)
				{
					this->currentSceneState = SceneState::QUIT;
					break;
				}
			}
		}

		// can't use range based for as bullets may be added to vector while looping
		for (size_t objectIndex = 0; objectIndex < gameObjects.size(); objectIndex++)
		{
			gameObjects[objectIndex]->Update(deltaTime, gameObjects, this->window);
		}


		// clears the background with the color black
		SDL_SetRenderDrawColor(this->renderer,
			this->clearColor.r, this->clearColor.g, this->clearColor.b, this->clearColor.a);
		SDL_RenderClear(this->renderer);


		SDL_SetRenderDrawColor(this->renderer, this->drawColor.r, this->drawColor.g, this->drawColor.b, this->drawColor.a);
		for (size_t objectIndex = 0; objectIndex < gameObjects.size(); objectIndex++)
		{
			// front is called to get the pointer to the first element from the vector
			SDL_RenderDrawLines(this->renderer, &gameObjects[objectIndex]->GetDrawableCoords().front(),
				gameObjects[objectIndex]->GetDrawableCoords().size());

			// used to draw the center, not necessary
			SDL_RenderDrawPoint(this->renderer, (int)gameObjects[objectIndex]->center.x, (int)gameObjects[objectIndex]->center.y);
		}

		// push to screen
		SDL_RenderPresent(this->renderer);
	}*/
}
