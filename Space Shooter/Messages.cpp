#include "Messages.h"



Msg::Msg()
{
}

Msg::Msg(MsgTypes msgType, System * sourceSystem)
{
	this->msgType = msgType;
	this->sourceSystem = sourceSystem;
}

Msg::~Msg()
{
}

/*---Create Object Message---*/

CreateObjMsg::CreateObjMsg()
{
}

CreateObjMsg::CreateObjMsg(MsgTypes msgType, System* sourceSystem)
	: Msg(msgType, sourceSystem)
{
}

CreateObjMsg::~CreateObjMsg()
{
}

/*---Delete Object Message---*/
DeleteObjMsg::DeleteObjMsg()
{
}

DeleteObjMsg::DeleteObjMsg(MsgTypes msgType, System * sourceSystem)
	: Msg(msgType, sourceSystem)
{
}

DeleteObjMsg::~DeleteObjMsg()
{
}

/*---Collision Detection Message---*/

CollisionMsg::CollisionMsg()
{
}

CollisionMsg::CollisionMsg(MsgTypes msgType, System * sourceSystem)
	: Msg(msgType, sourceSystem)
{
}

CollisionMsg::~CollisionMsg()
{
}
