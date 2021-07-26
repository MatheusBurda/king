#pragma once
#include"stdafx.h"
#include"EntityList.h"
class CollisionManager
{
private:
	EntityList* list;


public:
	CollisionManager(EntityList* pList);
	~CollisionManager();
	void toCollide();
	void setList(EntityList* pList) { list = pList; }
};

