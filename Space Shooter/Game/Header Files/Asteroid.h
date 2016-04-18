#pragma once

#include "../../Engine/Header Files/GameObject.h"



class Asteroid :
	public GameObject
{
public:

	Asteroid(Vector2D* vertices, int noOfVertices, Vector2D* meshVertices, int noOfmeshVerts);

	~Asteroid();

	virtual void Update(double dTime) override;

private:
	int rotateAmount;
};