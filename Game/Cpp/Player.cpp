#include "Player.h"
#include "Bullet.h"
#include "LogicManager.h"


Player::Player(Vector2D * vertices, int noOfVertices, Vector2D* meshVertices, int noOfmeshVerts)
	: GameObject(vertices, noOfVertices, meshVertices, noOfmeshVerts)
{
	this->rotateAmount = 200;
	this->currentVel = 0;
	this->accelRate = 20;
	this->maxVel = 25;
	this->minVel = 0;

	this->shootDelay = 0.25f;
	this->timeSinceLastShot = 0;
	this->weaponShot = false;

	this->handle.type = GameObjectTypes::PLAYER;
}

Player::~Player()
{
}

void Player::Update(double dTime, LogicManager* const logicManager)
{
	const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
	if (keyboardState[SDL_SCANCODE_LEFT])
	{
		this->mesh.RotateVertices(-this->rotateAmount * dTime);
	}
	if (keyboardState[SDL_SCANCODE_RIGHT])
	{
		this->mesh.RotateVertices(this->rotateAmount * dTime);
	}
	if (keyboardState[SDL_SCANCODE_UP])
	{
		this->currentVel = (this->currentVel >= this->maxVel) ? this->maxVel : this->currentVel + this->accelRate * dTime;
	}
	if (keyboardState[SDL_SCANCODE_DOWN])
	{
		this->currentVel = (this->currentVel <= this->minVel) ? this->minVel : this->currentVel - this->accelRate * dTime;
	}
	this->rigidBody.velocity = this->mesh.forwardDirection * this->currentVel;
	
	if (keyboardState[SDL_SCANCODE_SPACE] && !weaponShot)
	{
		Bullet* newBullet = static_cast<Bullet*>(CreateObject(logicManager, GameObjectTypes::BULLET));
		newBullet->rigidBody.position = this->rigidBody.position;
		newBullet->rigidBody.velocity = this->mesh.forwardDirection.GetUnitVector() * 1000;

		weaponShot = true;
	}
	timeSinceLastShot += dTime;
	if (this->timeSinceLastShot > this->shootDelay)
	{
		weaponShot = false;
		timeSinceLastShot = 0;
	}
}

void Player::OnCollision(const GameObject* const collidedObj, LogicManager* const logicManager)
{
	if (collidedObj->handle.type == GameObjectTypes::ASTEROID)
	{
		DeleteObject(logicManager, this->handle.index);
	}
}
