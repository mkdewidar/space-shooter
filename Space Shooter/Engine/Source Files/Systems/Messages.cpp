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

DeleteObjectMsg::DeleteObjectMsg()
{
	this->msgType = MsgTypes::DELETEOBJECTMSG;
}

DeleteObjectMsg::~DeleteObjectMsg()
{
}

//---Object Collision Msg---//

CollisionMsg::CollisionMsg()
{
	this->msgType = MsgTypes::COLLISIONMSG;
}

CollisionMsg::~CollisionMsg()
{
}
