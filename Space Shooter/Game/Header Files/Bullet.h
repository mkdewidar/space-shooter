#pragma once

#include "../../Engine/Header Files/GameObject.h"

/*
Class defining a bullet
*/
class Bullet :
	public GameObject
{
public:
	Bullet(Vector2D origin, Vector2D* vertices, int noOfVertices, Vector2D direction);
	~Bullet();

	void Update(double dTime) override;
};

