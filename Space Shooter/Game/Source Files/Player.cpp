#include "../Header Files/Player.h"
#include "../Header Files/Bullet.h"


Player::Player(Vector2D center, Vector2D * vertices, int noOfVertices)
	: GameObject(center, vertices, noOfVertices)
{
	this->accelRate = 300;
	this->maxVel = 500;
}

Player::~Player()
{
}

void Player::Update(double dTime)
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

	 
	//if (keyboardState[SDL_SCANCODE_SPACE])
	//{
	//	// Vector2D bulletShape[2] = { {0, 0 }, {0, 10 } };		<-- use later to make bullets look better
	//	Bullet* newBullet = new Bullet(this->GetWorldCoords()[0], &Vector2D(0, 0), 1, this->forwardDirection);
	//	gameObjects.push_back(newBullet);
	//	newBullet->handle = gameObjects.size() - 1;
	//}


	//for (size_t objectIndex = 0; objectIndex < gameObjects.size(); objectIndex++)
	//{
	//	// if the coords are the same that's yourself!!
	//	if ((gameObjects[objectIndex]->center.x == this->center.x) 
	//		&& (gameObjects[objectIndex]->center.y == this->center.y))
	//	{
	//		continue;
	//	}
	//	this->AmIColliding(gameObjects[objectIndex]);
	//}

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