#include "../../Header Files/Systems/GameState.h"



GameState::GameState()
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
	default:
	{
		break;
	}
	}
}
