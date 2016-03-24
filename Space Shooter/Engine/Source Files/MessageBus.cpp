#include "../Header Files/MessageBus.h"



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
	// TODO: INSERT LOOP WHICH GOES THROUGH ALL SYSTEMS AND CALLS HANDLE MESSAGE
}
