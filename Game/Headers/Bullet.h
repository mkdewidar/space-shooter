#pragma once

#include "../../Engine/Header Files/GameObject.h"
#include "../../Engine/Header Files/Systems/Renderer.h"
#include "../../Engine/Header Files/Systems/LogicManager.h"

class Bullet
	: public GameObject
{
public:
	Bullet(Vector2D* vertices, int noOfVertices,
		Vector2D* meshVertices, int noOfmeshVerts);
	~Bullet();

	void Update(double dTime, LogicManager* const logicManager) override;

	void OnCollision(const GameObject* const collidedObj, LogicManager* const logicManager) override;
};