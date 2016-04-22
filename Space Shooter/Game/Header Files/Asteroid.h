#pragma once

#include "../../Engine/Header Files/GameObject.h"


class Asteroid :
	public GameObject
{
public:

	Asteroid(Vector2D* vertices, int noOfVertices, Vector2D* meshVertices, int noOfmeshVerts);

	~Asteroid();

	void Update(double dTime, const MessageBus* const msgBus) override;

	void OnCollision(const GameObject* const collidedObj) override;

private:
	int rotateAmount;
};