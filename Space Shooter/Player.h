#pragma once

#include "GameObject.h"



class Player : public GameObject
{
public:
	Player(Vector2D center, Vector2D* vertices, int noOfVertices);
	~Player();

	virtual void Update(double dTime, vector<GameObject*>& gameObjects, SDL_Window*& window) override;
};

