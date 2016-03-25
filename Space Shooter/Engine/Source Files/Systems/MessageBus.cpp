#include "../../Header Files/Systems/MessageBus.h"



MessageBus::MessageBus()
{
}


MessageBus::~MessageBus()
{
}

void MessageBus::SetupMsgBusReferences(vector<System*> gameSystems)
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
