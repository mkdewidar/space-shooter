#pragma once

#include <vector>
#include "Messages.h"
#include "System.h"

using std::vector;

/*
Defines the bus that is used for communication between
systems
*/
class MessageBus
{
public:
	MessageBus(vector<System*> gameSystems);
	~MessageBus();

	/*
	Pushes the message provided onto the stack
	@param newMsg pointer to the new message to be posted
	*/
	void PostMessage(Msg* newMsg);

private:
	vector<System*> systems;
};