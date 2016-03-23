#include "LogicManager.h"



LogicManager::LogicManager(vector<GameObject*>* gameObjects, MessageBus* messageBus)
	: System(gameObjects, messageBus)
{
}

LogicManager::~LogicManager()
{
}

void LogicManager::Update(double dTime)
{
	for (size_t index = 0; index < this->objects->size(); index++)
	{
		(*this->objects)[index]->Update(dTime);
	}
}

void LogicManager::HandleMessage(Msg * msg)
{
}
