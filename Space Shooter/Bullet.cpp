#include "Bullet.h"



Bullet::Bullet(Vector2D center, Vector2D* vertices, int noOfVertices, Vector2D direction)
	: GameObject(center, vertices, noOfVertices)
{
	this->tag = ObjectTags::BULLET;
	this->maxVel = 600;
	this->movementVector = direction.GetUnitVector() * this->maxVel;
}


Bullet::~Bullet()
{
}

void Bullet::Update(double dTime, vector<GameObject*>& gameObjects, SDL_Window *& window)
{
	GameObject::Update(dTime, gameObjects, window);
}
