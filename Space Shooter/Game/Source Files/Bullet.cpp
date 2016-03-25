#include "../Header Files/Bullet.h"



Bullet::Bullet(Vector2D center, Vector2D* vertices, int noOfVertices, Vector2D direction)
	: GameObject(center, vertices, noOfVertices)
{
	this->maxVel = 600;
	this->movementVector = direction.GetUnitVector() * this->maxVel;
}


Bullet::~Bullet()
{
}

void Bullet::Update(double dTime)
{
	this->currentVel = (this->currentVel < this->minVel) ? this->minVel : this->currentVel;
	this->currentVel = (this->currentVel > this->maxVel) ? this->maxVel : this->currentVel;

	this->center = this->center + (this->movementVector * dTime);
}
