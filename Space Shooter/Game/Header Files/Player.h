#pragma once

#include "../../Engine/Header Files/GameObject.h"


/*
Defines the player ship that the player controls
*/
class Player 
	: public GameObject
{
public:
	Player(Vector2D* vertices, int noOfVertices);
	~Player();

	virtual void Update(double dTime) override;

private:
	// amount of rotation to be applied to an objects vertices
	double rotateAmount = 200;
	double currentVel = 0;
	double accelRate = 20;

	int maxVel = 50;
	int minVel = 0;
};

