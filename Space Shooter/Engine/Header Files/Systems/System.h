#pragma once

#include <vector>
#include "../GameObject.h"
#include "MessageBus.h"

using std::vector;

class MessageBus;

/*
Defines the basic requirements for any game system
*/
class System
{
public:
	System();
	~System();

	/*
	Update function for the system, to be overiden by system
	@param gameObjects all the game objects that the system acts on
	@param dt time taken to complete previous frame
	*/
	virtual void Update(double dTime) = 0;

	/*
	Handles the message that was passed to it
	*/
	virtual void HandleMessage(Msg* postedMsg) = 0;

	/*
	Sets up system references to the game objects and the message bus
	@param gameObjects all the game objects that the system should be
		aware of
	@param messageBus the message bus that the system should use
		for communication with other systems
	*/
	void SetupMsgBusReferences(MessageBus* msgBus, vector<GameObject*>* gameObjects);

protected:
	// the message bus that the system posts messages to
	MessageBus* messageBus;

	// pointer to the vector of game objects in the game
	vector<GameObject*>* objects;
};