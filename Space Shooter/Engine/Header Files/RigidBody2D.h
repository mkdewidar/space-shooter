#pragma once

#include "GameComponent.h"
#include "Vector2D.h"

/*
Defines the basic physics properties
*/
class RigidBody2D
	: public GameComponent
{
public:
	RigidBody2D();
	~RigidBody2D();

	Vector2D position;
	Vector2D velocity;
};

