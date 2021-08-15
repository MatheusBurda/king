#pragma once

#include "Entity.h"
#include "Character.h"
#include "List.h"
#include"Obstacle.h"
#include "Projectile.h"
#include "stdafx.h"

class EntityList {
private:
    List<Entity> list;

public:
    EntityList();
    ~EntityList();

    void updateAll(float dt);
    void renderAll();
    void addEntity(Entity* pNew);
    void removeEntity(Entity* pDel);
    void deleteAll();
    void deleteAllButPLayers();
    const List<Entity>* getList() { return &list; }
    int getSize() { return list.length(); }
    Entity* operator[](int x);
};
