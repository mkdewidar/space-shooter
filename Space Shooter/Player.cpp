#include "Player.h"



Player::Player(Vector2D center, Vector2D * vertices, int noOfVertices)
	: GameObject(center, vertices, noOfVertices)
{
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
	if (keyboardState[SDL_SCANCODE_UP] && (this->currentForwardVel <= this->maxVel))
	{
		this->currentForwardVel += this->accelRate * dTime;
	}
	if (keyboardState[SDL_SCANCODE_DOWN] && (this->currentForwardVel > this->minVel))
	{
		this->currentForwardVel -= this->accelRate * dTime;
	}

	this->OffsetForward(this->currentForwardVel * dTime);


	for (GameObject* object : gameObjects)
	{
		// if the coords are the same that's yourself!!
		if ((object->center.x == this->center.x) && (object->center.y == this->center.y))
		{
			continue;
		}
		this->AmIColliding(object);
	}

	// the base class's update function has the boundary check functionality.
	GameObject::Update(dTime, gameObjects, window);
}