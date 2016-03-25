#pragma once

#include "../../Engine/Header Files/GameObject.h"


/*
Defines the player ship that the player controls
*/
class Player 
	: public GameObject
{
public:
	Player(Vector2D center, Vector2D* vertices, int noOfVertices);
	~Player();

	virtual void Update(double dTime) override;
};

