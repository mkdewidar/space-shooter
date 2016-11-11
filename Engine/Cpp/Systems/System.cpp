#include "System.h"




System::System()
{
}

System::~System()
{
}

void System::SetupSystem(MessageBus * msgBus)
{
	this->messageBus = msgBus;
}
