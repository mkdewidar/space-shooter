#pragma once

#include "System.h"

/*
Defines system that manages the current game state
*/
class GameState :
	public System
{
public:
	GameState(SlotMap<GameObject*>& gameObjs);
	~GameState();

	/*
	Says whether the game is over and will close or not
	@return a bool representing whether the game is over or not
	*/
	bool IsItOver();

	void Update(double dTime) override;

	void HandleMessage(Msg* postedMsg) override;

private:
	bool quit;

	const SlotMap<GameObject*>& gameObjects;
};

