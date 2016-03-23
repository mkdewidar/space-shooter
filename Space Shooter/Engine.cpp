#include "Engine.h"

Engine::Engine()
{
	//---SDL initialisation---//

	this->window = SDL_CreateWindow(GAMENAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_BORDERLESS | SDL_WINDOW_SHOWN);

	this->renderer = SDL_CreateRenderer(window, 0, 0);
}


Engine::~Engine()
{
	for (GameObject* object : this->gameObjects)
	{
		delete object;
	}

	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
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
