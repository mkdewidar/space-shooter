#include "../../Header Files/Systems/Renderer.h"



Renderer::Renderer(SlotMap<GameObject*>& gameObjs)
	: gameObjects(gameObjs)
{
	this->window = SDL_CreateWindow(GAMENAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		Renderer::WIDTH, Renderer::HEIGHT, SDL_WINDOW_BORDERLESS | SDL_WINDOW_SHOWN);

	this->renderer = SDL_CreateRenderer(window, 0, 0);
}

Renderer::~Renderer()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
}

void Renderer::Update(double dTime)
{
	// clears the background with the color black
	SDL_SetRenderDrawColor(this->renderer,
		this->clearColor.r, this->clearColor.g, this->clearColor.b, this->clearColor.a);
	SDL_RenderClear(this->renderer);


	SDL_SetRenderDrawColor(this->renderer, this->drawColor.r, this->drawColor.g, this->drawColor.b, this->drawColor.a);

	for (size_t index = 0; index < this->gameObjects.Capacity(); index++)
	{
		GameObject* object = this->gameObjects[index];

		if (object == nullptr)
		{
			continue;
		}

		// front is called to get the pointer to the first element from the vector
		SDL_RenderDrawLines(this->renderer, 
			&(object->mesh.GetDrawableCoords(object->rigidBody.position).front()),
			object->mesh.GetDrawableCoords(object->rigidBody.position).size());
	}

	// push to screen
	SDL_RenderPresent(this->renderer);
}

void Renderer::HandleMessage(Msg * postedMsg)
{
}