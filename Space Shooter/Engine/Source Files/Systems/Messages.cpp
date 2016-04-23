#include "../../Header Files/Systems/Messages.h"



Msg::Msg()
{
}

Msg::~Msg()
{
}

//---End Game Msg---//

EndGameMsg::EndGameMsg()
{
	this->msgType = MsgTypes::ENDGAME;
}

EndGameMsg::~EndGameMsg()
{
}

//---Create Object Msg---//
CreateObjectMsg::CreateObjectMsg(GameObjectTypes objType)
{
	this->msgType = MsgTypes::CREATEOBJECTMSG;
	this->objType = objType;
}

CreateObjectMsg::~CreateObjectMsg()
{
}

//---Delete Object Msg---//

DeleteObjectMsg::DeleteObjectMsg(int objToDel)
{
	this->msgType = MsgTypes::DELETEOBJECTMSG;
	this->objToDel = objToDel;
}

DeleteObjectMsg::~DeleteObjectMsg()
{
}

//---Object Collision Msg---//

CollisionMsg::CollisionMsg(Identifier objHandle, Identifier otherObjHandle)
{
	this->msgType = MsgTypes::COLLISIONMSG;
	this->objHandle = objHandle;
	this->otherObjHandle = otherObjHandle;
}

CollisionMsg::~CollisionMsg()
{
}
