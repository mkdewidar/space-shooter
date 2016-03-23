#pragma once

#include <SDL.h>
#include "TimeManager.h"
#include "ObjectManager.h"
#include "LogicManager.h"
#include "Physics.h"
#include "Renderer.h"

#define SCREENWIDTH 1600
#define SCREENHEIGHT 900
#define GAMENAME "Space Shooter"

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
	// pointer to the SDL window
	SDL_Window* window = NULL;

	// pointer to the SDL renderer
	SDL_Renderer* renderer = NULL;

	// variable used to store current event in event queue
	SDL_Event e;

	// color used to clear the background
	SDL_Color clearColor{ 0, 0, 0, 0 };
	SDL_Color drawColor{ 0, 200, 255, 0 };

	// object that allows time capabilities
	TimeManager time;

	// vector of all the game objects in the scene
	vector<GameObject*> gameObjects;

	ObjectManager
};

