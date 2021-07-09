#include "EntityList.h"

EntityList::EntityList() :
    list() {
}

EntityList::~EntityList() {
}

void EntityList::updateAll() {
    int size = list.length();
    Entity* pAux;
    for (int i = 0; i < size; i++) {
        pAux = list[i];
        pAux->update();
    }
}

void EntityList::renderAll() {
    int size = list.length();
    Entity* pAux;
    for (int i = 0; i < size; i++) {
        pAux = list[i];
        pAux->render();
    }
}

void EntityList::addEntity(Entity* pNew) {
    list.append(pNew);
}

void EntityList::removeEntity(Entity* pDel) {
}
