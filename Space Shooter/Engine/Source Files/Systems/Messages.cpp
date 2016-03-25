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
