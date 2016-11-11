#include "../../Header Files/Systems/LogicManager.h"
#include "../../Header Files/Systems/Renderer.h"

LogicManager::LogicManager(SlotMap<GameObject*>& gameObjs)
	: gameObjects(gameObjs)
{
}

LogicManager::~LogicManager()
{
}

void LogicManager::Update(double dTime)
{
	while (SDL_PollEvent(&this->e) != 0)
	{
		if (this->e.type == SDL_KEYDOWN)
		{
			if (this->e.key.keysym.sym == SDLK_ESCAPE)
			{
				EndGameMsg msg;
				this->messageBus->PostMessage(&msg);
				break;
			}
		}
	}

	
	for (size_t index = 0; index < this->gameObjects.Capacity(); index++)
	{
		// used to simplify the statements below
		GameObject* object = this->gameObjects[index];

		if (object == nullptr)
		{
			continue;
		}

		object->Update(dTime, this);

		object->rigidBody.position.x = (object->rigidBody.position.x > Renderer::WIDTH) ?
			0 : object->rigidBody.position.x;
		object->rigidBody.position.x = (object->rigidBody.position.x < 0) ?
			Renderer::WIDTH : object->rigidBody.position.x;

		object->rigidBody.position.y = (object->rigidBody.position.y > Renderer::HEIGHT) ?
			0 : object->rigidBody.position.y;
		object->rigidBody.position.y = (object->rigidBody.position.y < 0) ?
			Renderer::HEIGHT : object->rigidBody.position.y;

		// updates the rigid body collision mesh to be same as mesh
		// required cause if mesh rotates the collision mesh should 
		// be rotated to be the same
		object->rigidBody.collisionMesh = object->mesh;
	}
}

void LogicManager::HandleMessage(Msg * postedMsg)
{
	switch (postedMsg->msgType)
	{
	case MsgTypes::COLLISIONMSG:
	{
		CollisionMsg* colMsg = static_cast<CollisionMsg*>(postedMsg);
		this->gameObjects[colMsg->objHandle.index]->OnCollision(this->gameObjects[colMsg->otherObjHandle.index], this);

		break;
	}
	}
}

void DeleteObject(LogicManager * logicManager, int objIndex)
{
	DeleteObjectMsg delMsg = DeleteObjectMsg(objIndex);
	logicManager->messageBus->PostMessage(&delMsg);
}

GameObject* CreateObject(LogicManager * logicManager, GameObjectTypes objType)
{
	CreateObjectMsg createMsg = CreateObjectMsg(objType);
	logicManager->messageBus->PostMessage(&createMsg);
	return createMsg.createdObject;
}
