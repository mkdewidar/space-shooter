#include "../Header Files/GameObject.h"
#include <Windows.h>



GameObject::GameObject(Vector2D* vertices, int noOfVertices, Vector2D* meshVertices, int noOfmeshVerts)
	: mesh(vertices, noOfVertices)
	, rigidBody(meshVertices, noOfmeshVerts)
{
}


GameObject::~GameObject()
{
}