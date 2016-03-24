#pragma once

#include "VectorShape.h"

/*
Enum representing all tags that can be assigned to game objects
*/
enum ObjectTags
{
	PLAYER,
	ASTEROID,
	BULLET
};

/*
The base class for any game object that can exist
in the game.
*/
class GameObject : public VectorShape
{
public:
	// string which serves as a description of sorts for the object
	ObjectTags tag;

	// a number which is used to directly access the object amongst other objects
	unsigned handle;

	/*
	Creates an game object
	@param center the center coordinates for the game object
	@param vertices the vertices that define the shape of the game object
		relative to the center coordinate going clockwise
	@param noOfVertices the number of vertices for the shape
	*/
	GameObject(Vector2D center, Vector2D* vertices, int noOfVertices);
	~GameObject();

	/*
	Updates the game object every frame
	@param dTime the time taken to process the last frame
	@param gameObjects a reference to all the game objects
		in the game
	*/
	virtual void Update(double dTime, vector<GameObject*>& gameObjects, SDL_Window*& window);

	/*
	Gets a radius value which is used to check the proximity
		to other objects using circle collision
	@return an int which represents a radius to be used as a
		proximity check using circle collision.
	*/
	int GetProximity();

protected:
	// proximity radius relative to center of the shape
	int proximity = 100;

	// amount of rotation to be applied to an objects vertices
	double rotateAmount = 200;

	// a vector representing the direction and magnitude that
	// an object needs to move in
	Vector2D movementVector{};

	double currentVel = 0;
	double accelRate = 100;

	int maxVel = 500;
	int minVel = 0;


	/*
	Performs the seperating axis collision between this object and
	another provided game object
	@return a bool representing whether collision occured or not
	*/
	bool AmIColliding(GameObject* otherObject);
};

