#pragma once

class System;

/*This file defines all the messages that are the used in the system*/

// need to prevent anyone from making an instant of this class

enum MsgTypes
{
	CREATEOBJECTMSG,
	DELETEOBJECTMSG,
	COLLISIONMSG,
	ENDGAME
};

class Msg
{
public:
	Msg();
	~Msg();

	MsgTypes msgType;
	// TODO: can avoid system messaging itself by adding a source system member.
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

	// TODO: members to identify the object to be created
};

class DeleteObjectMsg
	: public Msg
{
public:
	DeleteObjectMsg();
	~DeleteObjectMsg();

	// TODO: members to identify the object to be deleted
};

class CollisionMsg
	: public Msg
{
public:
	CollisionMsg();
	~CollisionMsg();

	// TODO: members to identify the objects that have collided
};