#include "..\Header Files\Bullet.h"

Bullet::Bullet(Vector2D* vertices, int noOfVertices,
	Vector2D* meshVertices, int noOfmeshVerts)
	: GameObject(vertices, noOfVertices, meshVertices, noOfmeshVerts)
{
	this->handle.type = GameObjectTypes::BULLET;
}

Bullet::~Bullet()
{
}

void Bullet::Update(double dTime, LogicManager * const logicManager)
{
	if (this->rigidBody.position.x > Renderer::WIDTH
		|| this->rigidBody.position.x < 0
		|| this->rigidBody.position.y > Renderer::HEIGHT
		|| this->rigidBody.position.y < 0)
	{
		DeleteObject(logicManager, this->handle.index);
	}
}

void Bullet::OnCollision(const GameObject * const collidedObj, LogicManager * const logicManager)
{
	if (collidedObj->handle.type == GameObjectTypes::ASTEROID)
	{
		DeleteObject(logicManager, collidedObj->handle.index);
		DeleteObject(logicManager, this->handle.index);
	}
}
