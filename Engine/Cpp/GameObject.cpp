#include "GameObject.h"
#include "LogicManager.h"



GameObject::GameObject(Vector2D* vertices, int noOfVertices, Vector2D* meshVertices, int noOfmeshVerts)
	: mesh(vertices, noOfVertices),
	rigidBody(meshVertices, noOfmeshVerts)
{
}


GameObject::~GameObject()
{
}