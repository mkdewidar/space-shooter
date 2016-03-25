#include "../../Header Files/Systems/LogicManager.h"



LogicManager::LogicManager()
{
}

LogicManager::~LogicManager()
{
}

void LogicManager::Update(double dTime)
{
	while (SDL_PollEvent(&this->e) != 0)
	{
		if (this->e.type == SDL_KEYDOWN)
		{
			if (this->e.key.keysym.sym == SDLK_ESCAPE)
			{
				EndGameMsg msg;
				this->messageBus->PostMessage(&msg);
				break;
			}
		}
	}

	for (size_t objectIndex = 0; objectIndex < this->objects->size(); objectIndex++)
	{
		(*this->objects)[objectIndex]->Update(dTime);
	}
}

void LogicManager::HandleMessage(Msg * postedMsg)
{
	// TODO: INSERT MESSAGE HANDELING CODE HERE
}