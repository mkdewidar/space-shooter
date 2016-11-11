#pragma once

#include "GameComponent.h"
#include "Vector2D.h"
#include "Mesh2D.h"

/*
Defines the basic physics properties
*/
class RigidBody2D
	: public GameComponent
{
public:
	RigidBody2D(Vector2D* meshVerts, int noOfVertices);
	~RigidBody2D();

	Vector2D position;
	Vector2D velocity;

	// this is seperate from the mesh that is drawn to maybe allow 
	// for more detailed meshes without having all edges be part of
	// collision detection
	Mesh2D collisionMesh;
	// used to check if objects are within sensible range before 
	// starting the collision check between the two objects
	int proximity;
};

