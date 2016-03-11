#include "Bullet.h"



Bullet::Bullet(Vector2D center, Vector2D* vertices, int noOfVertices, Vector2D direction)
	: GameObject(center, vertices, noOfVertices)
{
}


Bullet::~Bullet()
{
}

void Bullet::Update(double dTime, vector<GameObject*>& gameObjects, SDL_Window *& window)
{

}
