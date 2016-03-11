#pragma once

#include <SDL.h>
#include "VectorShape.h"
#include "TimeManager.h"
#include "Vector2D.h"
#include "Player.h"
#include "Asteroid.h"

#define SCREENWIDTH 1600
#define SCREENHEIGHT 900
#define GAMENAME "Space Shooter"

/*
Enum representing the states of the scene
*/
enum SceneState
{
	QUIT,
	GAMESCENE
};

/*
A class that defines a scene
*/
class Scene
{
public:

	// keeps track of the current scene
	SceneState currentSceneState = GAMESCENE;

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

	/*
	Constructor for the scene, initialises the scene, game objects
		and other related objects
	*/
	Scene();
	
	/*
	Destructor for the scene, manages cleanup for the scene
	*/
	~Scene();

	/*
	Main functionality of the scene, contains main loop
	*/
	void RunScene();
};

