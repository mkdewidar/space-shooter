#include "../../Header Files/Systems/LogicManager.h"

#include "../../Header Files/Systems/Renderer.h"

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

	
	for (GameObject* object : (*this->objects))
	{
		object->Update(dTime);

		object->rigidBody.position.x = (object->rigidBody.position.x > Renderer::WIDTH) ?
			0 : object->rigidBody.position.x;
		object->rigidBody.position.x = (object->rigidBody.position.x < 0) ?
			Renderer::WIDTH : object->rigidBody.position.x;

		object->rigidBody.position.y = (object->rigidBody.position.y > Renderer::HEIGHT) ?
			0 : object->rigidBody.position.y;
		object->rigidBody.position.y = (object->rigidBody.position.y < 0) ?
			Renderer::HEIGHT : object->rigidBody.position.y;

	}
}

void LogicManager::HandleMessage(Msg * postedMsg)
{
	// TODO: INSERT MESSAGE HANDELING CODE HERE
}