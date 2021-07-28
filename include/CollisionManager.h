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

	void moveX(Entity* ent1, Entity* ent2, float intersectX);
	void moveY(Entity* ent1, Entity* ent2, float intersectY);
	void notAbove(Entity* ent1, Entity* ent2, float intersectX, float dx);
	void collidePlayer(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY);
	void collideEnemy(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY);
};

