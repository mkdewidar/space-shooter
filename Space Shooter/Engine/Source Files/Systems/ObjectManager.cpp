#include "../../Header Files/Systems/ObjectManager.h"

#include "../../Header Files/Mesh2D.h"
#include "../../Header Files/Vector2D.h"
#include "../../../Game/Header Files/Player.h"
#include "../../../Game/Header Files/Asteroid.h"

#define PLAYERPOSITIONS { 300, 500 }
#define PLAYERSHAPES { { 0, 20 },{ 10, -10 },{ -10, -10 } }

#define ASTEROIDPOSITIONS { 800, 500 }
#define ASTEROIDSHAPE { { 0, 45 },{ 40, 30 },{ 40, -30 },{ 0, -45 },{ -40, -30 },{ -40, 30 } }


ObjectManager::ObjectManager(SlotMap<GameObject*>& gameObjs)
	: gameObjects(gameObjs)
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
	if (postedMsg->msgType == MsgTypes::CREATEOBJECTMSG)
	{
		// TODO: ADD CODE TO CREATE OBJECT BASED ON DATA IN THE MSG
		Vector2D vertices[3] = PLAYERSHAPES;
		Player* player = new Player(vertices, 3, vertices, 3);
		this->gameObjects.AddItem(player);

		Vector2D vertices2[6] = ASTEROIDSHAPE;
		int totalAsteroids = (rand() % 10) + 1;
		for (int noOfAsteroids = 0; noOfAsteroids < totalAsteroids; noOfAsteroids++)
		{
			Asteroid* asteroid = new Asteroid(vertices2, 6, vertices2, 6);
			this->gameObjects.AddItem(asteroid);
		}
	}
	if (postedMsg->msgType == MsgTypes::DELETEOBJECTMSG)
	{
		// TODO: DELETE THE OBJECT USING ITS HANDLE
	}
}
