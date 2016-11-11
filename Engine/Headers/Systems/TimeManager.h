#pragma once

#include <SDL.h>

class TimeManager
{
public:
	TimeManager();
	~TimeManager();

	/*
	Restarts the time manager's time counter
	*/
	void ResetTime();

	/*
	Returns the difference in time since the
		time manager was set
	@return the delta time in milliseconds
	*/
	Uint32 GetDeltaTime();

private:
	// time set as start time, is relative 
	// to the start of the SDL init
	Uint32 startTime;
};

