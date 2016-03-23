#include "Physics.h"



Physics::Physics(vector<GameObject*>* gameObjects, MessageBus * messageBus)
	: System(gameObjects, messageBus)
{
}

Physics::~Physics()
{
}

void Physics::Update(double dTime)
{
}

void Physics::HandleMessage(Msg * msg)
{
}
