#pragma once

#include <vector>
#include "Messages.h"
#include "System.h"

class System;

using std::vector;

/*
Defines the bus that is used for communication between the systems
*/
class MessageBus
{
public:
	MessageBus();
	~MessageBus();

	/*
	Must be called to define the systems that the bus will be connecting
	@param gameSystems a vector of pointers to all the game systems
		that the bus has to connect
	*/
	void SetupSystem(vector<System*> gameSystems);

	/*
	Posts the message on the bus, all the systems the bus is aware of 
		are called to handle the message provided immediately
	@param newMsg the new message that is to be posted
	*/
	void PostMessage(Msg* newMsg);

private:
	vector<System*> systems;
};