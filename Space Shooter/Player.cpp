#include "Player.h"
#include "Bullet.h"


Player::Player(Vector2D center, Vector2D * vertices, int noOfVertices)
	: GameObject(center, vertices, noOfVertices)
{
	this->tag = ObjectTags::PLAYER;
	this->accelRate = 300;
	this->maxVel = 500;
}

Player::~Player()
{
}

void Player::Update(double dTime, vector<GameObject*>& gameObjects, SDL_Window*& window)
{
	const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
	if (keyboardState[SDL_SCANCODE_LEFT])
	{
		this->RotateVertices(-this->rotateAmount * dTime);
	}
	if (keyboardState[SDL_SCANCODE_RIGHT])
	{
		this->RotateVertices(this->rotateAmount * dTime);
	}
	if (keyboardState[SDL_SCANCODE_UP] && (this->currentVel < this->maxVel))
	{
		this->currentVel += this->accelRate * dTime;
	}
	if (keyboardState[SDL_SCANCODE_DOWN] && (this->currentVel > this->minVel))
	{
		this->currentVel -= this->accelRate * dTime;
	}
	this->movementVector = this->forwardDirection.GetUnitVector() * this->currentVel;

	 
	if (keyboardState[SDL_SCANCODE_SPACE])
	{
		// Vector2D bulletShape[2] = { {0, 0 }, {0, 10 } };		<-- use later to make bullets look better
		Bullet* newBullet = new Bullet(this->GetWorldCoords()[0], &Vector2D(0, 0), 1, this->forwardDirection);
		gameObjects.push_back(newBullet);
		newBullet->handle = gameObjects.size() - 1;
	}


	for (size_t objectIndex = 0; objectIndex < gameObjects.size(); objectIndex++)
	{
		// if the coords are the same that's yourself!!
		if ((gameObjects[objectIndex]->center.x == this->center.x) 
			&& (gameObjects[objectIndex]->center.y == this->center.y))
		{
			continue;
		}
		this->AmIColliding(gameObjects[objectIndex]);
	}

	// the base class's update function has the boundary check functionality.
	GameObject::Update(dTime, gameObjects, window);
}