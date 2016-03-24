#include "../Header Files/ObjectManager.h"

#include "../../Game/Header Files/VectorShape.h"
#include "../../Game/Header Files/Vector2D.h"
#include "../../Game/Header Files/Player.h"
#include "../../Game/Header Files/Asteroid.h"

#define PLAYERPOSITIONS { 300, 500 }
#define PLAYERSHAPES { { 0, 20 },{ 10, -10 },{ -10, -10 } }

#define ASTEROIDPOSITIONS { 800, 500 }
#define ASTEROIDSHAPE { { 0, 45 },{ 40, 30 },{ 40, -30 },{ 0, -45 },{ -40, -30 },{ -40, 30 } }


ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::Update(double dTime)
{
}

void ObjectManager::HandleMessage(Msg* postedMsg)
{
	// TODO: Insert msg handeling code here
	//if (msg->msgType == MsgTypes::CREATEOBJECT)
	//{
	//	// TODO: ADD CODE TO CREATE OBJECT BASED ON DATA IN THE MSG
	//	Vector2D center = PLAYERPOSITIONS;
	//	Vector2D vertices[3] = PLAYERSHAPES;
	//	Player* player = new Player(center, vertices, 3);

	//	center = ASTEROIDPOSITIONS;
	//	Vector2D vertices2[6] = ASTEROIDSHAPE;
	//	int totalAsteroids = (rand() % 10) + 1;
	//	for (int noOfAsteroids = 0; noOfAsteroids < totalAsteroids; noOfAsteroids++)
	//	{
	//		this->objects->push_back(new Asteroid(center, vertices2, 6));
	//	}

	//	for (size_t index = 0; index < this->objects->size(); index++)
	//	{
	//		// need to deallocate the vector pointer before accessing any of the elements
	//		(*this->objects)[index]->handle = index;
	//	}
	//}
	//if (msg->msgType == MsgTypes::DELETEOBJECT)
	//{
	//	// TODO: DELETE THE OBJECT USING ITS HANDLE
	//}
}
