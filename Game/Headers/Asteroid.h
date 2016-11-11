#pragma once

#include "GameObject.h"


class Asteroid :
	public GameObject
{
public:

	Asteroid(Vector2D* vertices, int noOfVertices, Vector2D* meshVertices, int noOfmeshVerts);

	~Asteroid();

	void Update(double dTime, LogicManager* const logicManager) override;

	void OnCollision(const GameObject* const collidedObj, LogicManager* const logicManager) override;

private:
	int rotateAmount;
};