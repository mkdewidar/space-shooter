#pragma once

#include "System.h"

/*
Defines the system that calls the logic updates for all of the game objects
*/
class LogicManager
	: public System
{
	/*
	Function called by game objects to delete object
	@param logicManager since this is a friend function the reference to
		the logicManager is required
	@param objIndex the index of the object to be deleted
	*/
	friend void DeleteObject(LogicManager* logicManager, int objIndex);

	/*
	Function called by game objects to create object
	@param logicManager since this is a friend function the reference to
		the logicManager is required
	@param objType the type of the object to be created
	@return a pointer to the object that was created
	*/
	friend GameObject* CreateObject(LogicManager* logicManager, GameObjectTypes objType);
public:
	LogicManager(SlotMap<GameObject*>& gameObjs);
	~LogicManager();

	void Update(double dTime) override;

	void HandleMessage(Msg* postedMsg) override;

private:
	// variable used to store current event in event queue
	SDL_Event e;

	// ref to all the game objects in the game, obtained from the slot map
	const SlotMap<GameObject*>& gameObjects;
};