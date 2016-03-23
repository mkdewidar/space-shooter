#include "System.h"




System::System(vector<GameObject*>* gameObjects, MessageBus * messageBus)
{
	this->msgBus = messageBus;
	this->objects = gameObjects;
}

System::~System()
{
}
