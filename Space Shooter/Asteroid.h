#pragma once

#include "GameObject.h"



class Asteroid :
	public GameObject
{
public:

	Asteroid(Vector2D center, Vector2D* vertices, int noOfVertices);

	~Asteroid();

	virtual void Update(double dTime, vector<GameObject*>& gameObjects, SDL_Window*& window) override;
};