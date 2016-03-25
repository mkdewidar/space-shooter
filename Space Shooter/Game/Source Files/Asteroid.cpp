#include "../Header Files/Asteroid.h"



Asteroid::Asteroid(Vector2D center, Vector2D * vertices, int noOfVertices)
	: GameObject(center, vertices, noOfVertices)
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
	this->RotateVertices(this->rotateAmount * dTime);

	this->currentVel = (this->currentVel < this->minVel) ? this->minVel : this->currentVel;
	this->currentVel = (this->currentVel > this->maxVel) ? this->maxVel : this->currentVel;

	this->center = this->center + (this->movementVector * dTime);

	// Allows all objects to wrap around the screen,
	// currently based on center which means the bigger the object the more
	// awkward it is, should probably implement some sort of 

	//int winWidth, winHeight;
	//SDL_GetWindowSize(window, &winWidth, &winHeight);
	//
	//this->center.x = (this->center.x > winWidth) ? 0 : this->center.x;
	//this->center.x = (this->center.x < 0) ? winWidth : this->center.x;

	//this->center.y = (this->center.y > winHeight) ? 0 : this->center.y;
	//this->center.y = (this->center.y < 0) ? winHeight : this->center.y;
}
