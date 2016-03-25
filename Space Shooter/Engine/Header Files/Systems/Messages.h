#pragma once

class System;

/*This file defines all the messages that are the used in the system*/

// need to prevent anyone from making an instant of this class

enum MsgTypes
{
	CREATEOBJECTMSG,
	DELETEOBJECTMSG,
	OBJECTCOLLISIONMSG,
	ENDGAME
};

class Msg
{
public:
	Msg();
	~Msg();

	MsgTypes msgType;
	// TODO: TO PREVENT MESSAGING YOURSELF, MAYBE ADD SOURCESYSTEM
};

class EndGameMsg
	: public Msg
{
public:
	EndGameMsg();
	~EndGameMsg();
};

class CreateObjectMsg
	: public Msg
{
public:
	CreateObjectMsg();
	~CreateObjectMsg();
};