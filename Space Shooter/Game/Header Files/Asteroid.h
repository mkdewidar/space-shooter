#pragma once

#include "../../Engine/Header Files/GameObject.h"



class Asteroid :
	public GameObject
{
public:

	Asteroid(Vector2D origin, Vector2D* vertices, int noOfVertices);

	~Asteroid();

	virtual void Update(double dTime) override;
};