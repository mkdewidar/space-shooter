#pragma once

#include "Mesh2D.h"
#include "RigidBody2D.h"
#include "../../Game/Header Files/GameObjectTypes.h"

/*
The base class for any game object that can exist
in the game.
*/
class LogicManager;

struct Identifier
{
	int index;
	GameObjectTypes type;
};

class GameObject
{
public:
	/*
	Creates an game object
	@param vertices the vertices that define the shape of the game object
	relative to the origin coordinate going clockwise
	@param noOfVertices the number of vertices for the shape
	*/
	GameObject(Vector2D* vertices, int noOfVertices,
		Vector2D* meshVertices, int noOfmeshVerts);
	~GameObject();

	Identifier handle;

	Mesh2D mesh;
	RigidBody2D rigidBody;

	/*
	Updates the game object every frame
	@param dTime the time taken to process the last frame
	@param gameObjects a reference to all the game objects
		in the game
	@param logicManager a pointer to the logic manager, used to post messages
		to other systems and objects
	*/
	virtual void Update(double dTime, LogicManager* const logicManager) = 0;

	virtual void OnCollision(const GameObject* const collidedObj, LogicManager* const logicManager) = 0;
};

