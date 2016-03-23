#pragma once

#include <vector>
#include "GameObject.h"
#include "MessageBus.h"

using std::vector;

/*
Defines the basic requirements for any game system
*/
class System
{
public:
	System(vector<GameObject*>* gameObjects, MessageBus* messageBus);
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
	virtual void HandleMessage(Msg* msg) = 0;

protected:
	// message bus is used for communicating with other systems
	MessageBus* msgBus;

	// pointer to the vector of game objects in the game
	vector<GameObject*>* objects;
};

