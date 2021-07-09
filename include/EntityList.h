#pragma once

#include "List.h"
#include "Entity.h"

class EntityList
{
private:
    List<Entity> list;
public:
    EntityList();
    ~EntityList();

    void updateAll();
    void renderAll();
    void addEntity(Entity* pNew);
    void removeEntity(Entity* pDel);
};
