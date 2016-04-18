#include "../Header Files/Player.h"
#include "../Header Files/Bullet.h"


Player::Player(Vector2D * vertices, int noOfVertices, Vector2D* meshVertices, int noOfmeshVerts)
	: GameObject(vertices, noOfVertices, meshVertices, noOfmeshVerts)
{
	this->rotateAmount = 200;
	this->currentVel = 0;
	this->accelRate = 20;
	this->maxVel = 25;
	this->minVel = 0;
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
}