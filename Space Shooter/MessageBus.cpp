#include "MessageBus.h"



MessageBus::MessageBus(vector<System*> gameSystems)
{
	this->systems = gameSystems;
}

MessageBus::~MessageBus()
{
}

void MessageBus::PostMessage(Msg * newMsg)
{
	for (System* system : this->systems)
	{
		// TODO: ADD CHECK FOR CALLER SO U DON'T CALL ITSELF
		if (newMsg->sourceSystem == system)
		{
			continue;
		}
		system->HandleMessage(newMsg);
	}
}
