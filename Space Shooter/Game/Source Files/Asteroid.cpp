#include "../Header Files/Asteroid.h"



Asteroid::Asteroid(Vector2D * vertices, int noOfVertices, Vector2D* meshVertices, int noOfmeshVerts)
	: GameObject(vertices, noOfVertices, meshVertices, noOfmeshVerts)
{
	int randXMovement = (rand() % 500) - 250;
	int randYMovement = (rand() % 500) - 250;
	this->rigidBody.velocity = Vector2D(randXMovement, randYMovement);

	this->rotateAmount = rand() % 300;
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(double dTime, const MessageBus* const msgBus)
{
	this->mesh.RotateVertices(this->rotateAmount * dTime);
}

void Asteroid::OnCollision(const GameObject * const collidedObj)
{

}
