#pragma once

#include "GameObject.h"



class Asteroid :
	public GameObject
{
public:

	// rotation amount for the asteroid, continues to rotate by this every frame
	double rotateAmount = 200;

	Asteroid(Vector2D center, Vector2D* vertices, int noOfVertices);

	~Asteroid();

	virtual void Update(double dTime, vector<GameObject*>& gameObjects, SDL_Window*& window) override;

protected:
	// the direction that the asteroid moves in, different than forward in that it doesn't
	// have to be facing forward to move in this direction
	Vector2D movementVector;
};