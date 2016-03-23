#include "Renderer.h"



Renderer::Renderer(vector<GameObject*>* gameObjects, MessageBus * messageBus)
	: System(gameObjects, messageBus)
{
}

Renderer::~Renderer()
{
}

void Renderer::Update(double dTime)
{
}

void Renderer::HandleMessage(Msg * msg)
{
}
