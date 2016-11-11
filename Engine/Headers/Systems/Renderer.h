#pragma once

#include "System.h"

#define GAMENAME "Space Shooter"

/*
Defines the system that manages the drawing to the screen
*/
class Renderer
	: public System
{
friend class Mesh2D;
public:
	Renderer(SlotMap<GameObject*>& gameObjs);
	~Renderer();

	void Update(double dTime) override;

	void HandleMessage(Msg* postedMsg) override;

	static const int WIDTH = 1600;
	static const int HEIGHT = 900;

private:
	// pointer to the SDL window
	SDL_Window* window = NULL;

	// pointer to the SDL renderer
	SDL_Renderer* renderer = NULL;

	// color used to clear the background
	SDL_Color clearColor{ 0, 0, 0, 0 };

	// color of everything on the screen
	SDL_Color drawColor{ 0, 200, 255, 0 };

	// slot map of all the objects in the game
	const SlotMap<GameObject*>& gameObjects;
};

