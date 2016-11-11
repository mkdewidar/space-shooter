#include "MessageBus.h"



MessageBus::MessageBus()
{
}


MessageBus::~MessageBus()
{
}

void MessageBus::SetupSystem(vector<System*> gameSystems)
{
	this->systems = gameSystems;
}

void MessageBus::PostMessage(Msg* newMsg)
{
	for (System* system : this->systems)
	{
		system->HandleMessage(newMsg);
	}
}
