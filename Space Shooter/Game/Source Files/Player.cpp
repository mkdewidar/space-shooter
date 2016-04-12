#include "../Header Files/Player.h"
#include "../Header Files/Bullet.h"


Player::Player(Vector2D * vertices, int noOfVertices)
	: GameObject(vertices, noOfVertices)
{
}

Player::~Player()
{
}

void Player::Update(double dTime)
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
	//	if ((gameObjects[objectIndex]->origin.x == this->origin.x) 
	//		&& (gameObjects[objectIndex]->origin.y == this->origin.y))
	//	{
	//		continue;
	//	}
	//	this->AmIColliding(gameObjects[objectIndex]);
	//}

	// Allows all objects to wrap around the screen,
	// currently based on origin which means the bigger the object the more
	// awkward it is, should probably implement some sort of 
}