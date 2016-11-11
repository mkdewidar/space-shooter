#include "Engine.h"



int main(int argc, char* arg[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Engine game;

	game.RunScene();

	return 0;
}