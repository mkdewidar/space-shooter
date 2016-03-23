#pragma once

#include "System.h"

/*
This file contains all messages that are used in the engine
*/

enum MsgTypes
{
	DELETEOBJECT,
	CREATEOBJECT,
	COLLISIONDETCTED
};

class Msg
{
public:
	Msg();
	Msg(MsgTypes msgType, System* sourceSystem);
	~Msg();

	MsgTypes msgType;
	System* sourceSystem;
};


class CreateObjMsg
	: Msg
{
public:
	CreateObjMsg();
	CreateObjMsg(MsgTypes msgType, System* sourceSystem);
	~CreateObjMsg();

	// TODO: INSERT MSG SPECIFIC PROPERTIES HERE
	// --> type of object to create
};


class DeleteObjMsg
	: Msg
{
public:
	DeleteObjMsg();
	DeleteObjMsg(MsgTypes msgType, System* sourceSystem);
	~DeleteObjMsg();

	// TODO: INSERT MSG SPECIFIC PROPERTIES HERE
	// --> handle for object to delete
};


class CollisionMsg
	: Msg
{
public:
	CollisionMsg();
	CollisionMsg(MsgTypes msgType, System* sourceSystem);
	~CollisionMsg();

	// TODO: INSERT MSG SPECIFIC PROPERTIES HERE
	// --> Handle to object 1
	// --> Handle to object 2
};