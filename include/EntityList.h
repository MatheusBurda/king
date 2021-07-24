#pragma once

#include "Entity.h"
#include "List.h"
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
};
