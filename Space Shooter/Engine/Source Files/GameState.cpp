#include "../Header Files/GameState.h"



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