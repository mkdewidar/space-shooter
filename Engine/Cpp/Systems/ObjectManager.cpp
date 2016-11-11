#include "../../Header Files/Systems/ObjectManager.h"

#include "../../Header Files/Mesh2D.h"
#include "../../Header Files/Vector2D.h"
#include "../../../Game/Header Files/Player.h"
#include "../../../Game/Header Files/Asteroid.h"
#include "../../../Game/Header Files/Bullet.h"

#define PLAYERPOSITIONS { 300, 500 }
#define PLAYERSHAPES { { 0, 20 },{ 10, -10 },{ -10, -10 } }

#define ASTEROIDPOSITIONS { 800, 500 }
#define ASTEROIDSHAPE { { 0, 45 },{ 40, 30 },{ 40, -30 },{ 0, -45 },{ -40, -30 },{ -40, 30 } }

#define BULLETSHAPE { {0, 0 }, {0, 10 } }


ObjectManager::ObjectManager(SlotMap<GameObject*>& gameObjs)
	: gameObjects(gameObjs)
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::Update(double dTime)
{
	for (int id : this->cleanUpIDs)
	{
		delete this->gameObjects[id];
		this->gameObjects.RemoveItem(id);
	}
	cleanUpIDs.clear();
}

void ObjectManager::HandleMessage(Msg* postedMsg)
{
	// TODO: Insert msg handeling code here
	switch (postedMsg->msgType)
	{
	case MsgTypes::CREATEOBJECTMSG:
	{
		CreateObjectMsg* createMsg = static_cast<CreateObjectMsg*>(postedMsg);

		switch (createMsg->objType)
		{
		case GameObjectTypes::ASTEROID:
		{
			Vector2D vertices2[6] = ASTEROIDSHAPE;
			Asteroid* newAsteroid = new Asteroid(vertices2, 6, vertices2, 6);
			newAsteroid->handle.index = this->gameObjects.AddItem(newAsteroid);
			createMsg->createdObject = newAsteroid;

			break;
		}
		case GameObjectTypes::PLAYER:
		{
		{
			Vector2D vertices[3] = PLAYERSHAPES;
			Player* newPlayer = new Player(vertices, 3, vertices, 3);
			newPlayer->handle.index = this->gameObjects.AddItem(newPlayer);
			createMsg->createdObject = newPlayer;

			break;
		}
		}
		case GameObjectTypes::BULLET:
		{
			Vector2D bulletShape[1] = { Vector2D(0, 0) };
			Bullet* newBullet = new Bullet(bulletShape, 1, bulletShape, 1);
			newBullet->handle.index = this->gameObjects.AddItem(newBullet);
			createMsg->createdObject = newBullet;

			break;
		}
		}

		break;
	}
	case MsgTypes::DELETEOBJECTMSG:
	{
		DeleteObjectMsg* delMsg = static_cast<DeleteObjectMsg*>(postedMsg);
		this->cleanUpIDs.push_back(delMsg->objToDel);

		break;
	}
	}
}
