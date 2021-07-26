#include "EntityList.h"

EntityList::EntityList() :
    list() {
}

EntityList::~EntityList() {
    list.clear();
}

void EntityList::updateAll(float dt) {

    int size = list.length();
    Entity* pAux;
    for (int i = 0; i < size; i++) {
        pAux = list[i];
        pAux->update(dt);
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

void EntityList::deleteAll() {
    list.clear();
}
Entity* EntityList::operator[](int x) {

    if (x >= list.length() || x < 0) {
        std::cout << "ERROR: Segmentation fault on Entity. Exceeded boundaries." << std::endl;
        exit(1);
    }
    Entity* aux = list[x];
    return aux;
}