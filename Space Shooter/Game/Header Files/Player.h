#pragma once

#include "../../Engine/Header Files/GameObject.h"


/*
Defines the player ship that the player controls
*/
class Player 
	: public GameObject
{
public:
	Player(Vector2D* vertices, int noOfVertices, Vector2D* meshVertices, int noOfmeshVerts);
	~Player();

	void Update(double dTime, const MessageBus* const msgBus) override;

	void OnCollision(const GameObject* const collidedObj) override;

private:
	// amount of rotation to be applied to an objects vertices
	double rotateAmount;
	double currentVel;
	double accelRate;
	int maxVel;
	int minVel;
};

