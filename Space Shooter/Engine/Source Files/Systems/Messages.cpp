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

CreateObjectMsg::CreateObjectMsg()
{
	this->msgType = MsgTypes::CREATEOBJECTMSG;
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

CollisionMsg::CollisionMsg(int objIndex, int otherObjIndex)
{
	this->msgType = MsgTypes::COLLISIONMSG;
	this->objIndex = objIndex;
	this->otherObjIndex = otherObjIndex;
}

CollisionMsg::~CollisionMsg()
{
}
