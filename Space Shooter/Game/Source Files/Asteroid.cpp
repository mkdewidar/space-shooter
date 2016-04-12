#include "../Header Files/Asteroid.h"



Asteroid::Asteroid(Vector2D origin, Vector2D * vertices, int noOfVertices)
	: GameObject(origin, vertices, noOfVertices)
{
	int randXMovement = (rand() % 500) - 250;
	int randYMovement = (rand() % 500) - 250;
	this->movementVector = Vector2D(randXMovement, randYMovement);

	this->rotateAmount = rand() % 300;
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(double dTime)
{
	this->mesh.RotateVertices(this->rotateAmount * dTime);

	this->currentVel = (this->currentVel < this->minVel) ? this->minVel : this->currentVel;
	this->currentVel = (this->currentVel > this->maxVel) ? this->maxVel : this->currentVel;

	this->mesh.origin = this->mesh.origin + (this->movementVector * dTime);

	// Allows all objects to wrap around the screen,
	// currently based on origin which means the bigger the object the more
	// awkward it is, should probably implement some sort of 

	//int winWidth, winHeight;
	//SDL_GetWindowSize(window, &winWidth, &winHeight);
	//
	//this->origin.x = (this->origin.x > winWidth) ? 0 : this->origin.x;
	//this->origin.x = (this->origin.x < 0) ? winWidth : this->origin.x;

	//this->origin.y = (this->origin.y > winHeight) ? 0 : this->origin.y;
	//this->origin.y = (this->origin.y < 0) ? winHeight : this->origin.y;
}
