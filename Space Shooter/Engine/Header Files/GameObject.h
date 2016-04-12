#pragma once

#include "Mesh2D.h"
#include "RigidBody2D.h"

/*
The base class for any game object that can exist
in the game.
*/
class GameObject
{
public:
	// TODO: ADD A HANDLE WHICH IDENTIFIES THE OBJECT

	Mesh2D mesh;
	RigidBody2D rigidBody;

	/*
	Creates an game object
	@param vertices the vertices that define the shape of the game object
		relative to the origin coordinate going clockwise
	@param noOfVertices the number of vertices for the shape
	*/
	GameObject(Vector2D* vertices, int noOfVertices);
	~GameObject();

	/*
	Updates the game object every frame
	@param dTime the time taken to process the last frame
	@param gameObjects a reference to all the game objects
		in the game
	*/
	virtual void Update(double dTime) = 0;

	/*
	Gets a radius value which is used to check the proximity
		to other objects using circle collision
	@return an int which represents a radius to be used as a
		proximity check using circle collision.
	*/
	int GetProximity();

	// proximity radius relative to origin of the shape
	int proximity = 100;
};

