#pragma once

/*This file defines all the messages that are the used in the system*/

// need to prevent anyone from making an instant of this class

enum MsgTypes
{
	CREATEOBJECTMSG,
	DELETEOBJECTMSG,
	OBJECTCOLLISIONMSG
};

class Msg
{
public:
	Msg();
	~Msg();

	MsgTypes msgType;
};