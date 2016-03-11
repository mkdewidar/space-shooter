#pragma once

#include "GameObject.h"

/*
Class defining a bullet
*/
class Bullet :
	public GameObject
{
public:
	Bullet(Vector2D center, Vector2D* vertices, int noOfVertices, Vector2D direction);
	~Bullet();

	void Update(double dTime, vector<GameObject*>& gameObjects, SDL_Window*& window) override;
};

