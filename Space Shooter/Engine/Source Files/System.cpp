#include "../Header Files/System.h"




System::System()
{
}

System::~System()
{
}

void System::SetupMsgBusReferences(MessageBus * msgBus, vector<GameObject*>* gameObjects)
{
	this->messageBus = msgBus;
	this->objects = gameObjects;
}
