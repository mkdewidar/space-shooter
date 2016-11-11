#include "../../Header Files/Systems/TimeManager.h"



TimeManager::TimeManager()
{
	this->startTime = 0;
}

TimeManager::~TimeManager()
{
}

void TimeManager::ResetTime()
{
	this->startTime = SDL_GetTicks();
}

Uint32 TimeManager::GetDeltaTime()
{
	return ( SDL_GetTicks() - this->startTime );
}