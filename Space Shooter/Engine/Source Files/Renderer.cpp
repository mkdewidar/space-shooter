#include "../Header Files/Renderer.h"



Renderer::Renderer()
{
	this->window = SDL_CreateWindow(GAMENAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_BORDERLESS | SDL_WINDOW_SHOWN);

	this->renderer = SDL_CreateRenderer(window, 0, 0);
}

Renderer::~Renderer()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
}

void Renderer::Update(double dTime)
{
}

void Renderer::HandleMessage(Msg * postedMsg)
{
}