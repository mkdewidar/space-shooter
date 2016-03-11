#include "Asteroid.h"



Asteroid::Asteroid(Vector2D center, Vector2D * vertices, int noOfVertices)
	: GameObject(center, vertices, noOfVertices)
{
	int randXMovement = (rand() % 500) - 250;
	int randYMovement = (rand() % 500) - 250;
	movementVector = Vector2D(randXMovement, randYMovement);

	this->rotateAmount = rand() % 250;
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(double dTime, vector<GameObject*>& gameObjects, SDL_Window*& window)
{
	this->RotateVertices(this->rotateAmount * dTime);
	this->center = this->center + (this->movementVector * dTime);

	GameObject::Update(dTime, gameObjects, window);
}
