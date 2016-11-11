#pragma once

#include "GameObjectTypes.h"
#include "GameObject.h"

class System;

/*This file defines all the messages that are the used in the system*/

enum MsgTypes
{
	CREATEOBJECTMSG,
	DELETEOBJECTMSG,
	COLLISIONMSG,
	ENDGAME
};

// need to prevent anyone from making an instant of this class
class Msg
{
public:
	Msg();
	~Msg();

	MsgTypes msgType;
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
	CreateObjectMsg(GameObjectTypes objType);
	~CreateObjectMsg();

	GameObjectTypes objType;
	GameObject* createdObject;
};

class DeleteObjectMsg
	: public Msg
{
public:
	DeleteObjectMsg(int objToDel);
	~DeleteObjectMsg();

	int objToDel;
};

class CollisionMsg
	: public Msg
{
public:
	CollisionMsg(Identifier objHandle, Identifier otherObjHandle);
	~CollisionMsg();

	Identifier objHandle;
	Identifier otherObjHandle;
};