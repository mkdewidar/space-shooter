#include "Asteroid.h"



Asteroid::Asteroid(Vector2D center, Vector2D * vertices, int noOfVertices)
	: GameObject(center, vertices, noOfVertices)
{
	this->tag = ObjectTags::ASTEROID;
	
	int randXMovement = (rand() % 500) - 250;
	int randYMovement = (rand() % 500) - 250;
	this->movementVector = Vector2D(randXMovement, randYMovement);

	this->rotateAmount = rand() % 300;
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(double dTime, vector<GameObject*>& gameObjects, SDL_Window*& window)
{
	this->RotateVertices(this->rotateAmount * dTime);

	GameObject::Update(dTime, gameObjects, window);
}
