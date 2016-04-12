#include "../../Header Files/Systems/Physics.h"


Physics::Physics()
{
}

Physics::~Physics()
{
}

void Physics::Update(double dTime)
{
	for (GameObject* object : (*this->objects))
	{
		object->rigidBody.position = object->rigidBody.position + (object->rigidBody.velocity * dTime);
	}
}

void Physics::HandleMessage(Msg * postedMsg)
{
}