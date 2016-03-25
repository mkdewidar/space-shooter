#pragma once

#include "System.h"

#define SCREENWIDTH 1600
#define SCREENHEIGHT 900
#define GAMENAME "Space Shooter"

/*
Defines the system that manages the drawing to the screen
*/
class Renderer
	: public System
{
public:
	Renderer();
	~Renderer();

	void Update(double dTime) override;

	void HandleMessage(Msg* postedMsg) override;

private:
	// pointer to the SDL window
	SDL_Window* window = NULL;

	// pointer to the SDL renderer
	SDL_Renderer* renderer = NULL;

	// color used to clear the background
	SDL_Color clearColor{ 0, 0, 0, 0 };

	// color of everything on the screen
	SDL_Color drawColor{ 0, 200, 255, 0 };
};

