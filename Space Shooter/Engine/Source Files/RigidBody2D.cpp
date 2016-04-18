#include "../Header Files/RigidBody2D.h"



RigidBody2D::RigidBody2D(Vector2D* meshVerts, int noOfVertices)
	: collisionMesh(meshVerts, noOfVertices)
{
	this->position = { 200, 200 };
	this->velocity = { 0, 0 };
	this->proximity = 100;
}


RigidBody2D::~RigidBody2D()
{
}
