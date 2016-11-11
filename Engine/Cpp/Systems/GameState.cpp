#include "GameState.h"



GameState::GameState(SlotMap<GameObject*>& gameObjs)
	: gameObjects(gameObjs)
{
	this->quit = false;
}

GameState::~GameState()
{
}

bool GameState::IsItOver()
{
	return this->quit;
}

void GameState::Update(double dTime)
{
	if (this->gameObjects.Size() <= 1)
	{
		size_t noOfAsteroids = rand() % 10 + 1;
		for (size_t counter = 0; counter < noOfAsteroids; counter++)
		{
			CreateObjectMsg createAsteroidMsg = CreateObjectMsg(GameObjectTypes::ASTEROID);
			this->messageBus->PostMessage(&createAsteroidMsg);
		}
	}
}

void GameState::HandleMessage(Msg * postedMsg)
{
	switch (postedMsg->msgType)
	{
	case MsgTypes::ENDGAME:
	{
		this->quit = true;
		break;
	}
	}
}
