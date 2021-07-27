#include "EntityList.h"

EntityList::EntityList() :
list() {
}

EntityList::~EntityList() {
    list.clear();
}

/* Cicles through the list calling update method for each Entity. */
void EntityList::updateAll(float dt) {
    Entity* pAux;
    for (int i = 0; i < list.length(); i++) {
        pAux = list[i];
        pAux->update(dt);

        if (pAux->getId() == ID::enemy) {
            if (!(static_cast<Character*>(pAux))->amAlive())
                removeEntity(pAux);
        }
    }
}

/* Cicles through the list calling render method for each Entity. */
void EntityList::renderAll() {
    int size = list.length();
    Entity* pAux;
    for (int i = 0; i < size; i++) {
        if (list[i]->getShowing()) {
            pAux = list[i];
            pAux->render();
        }
    }
}

/* Add a Entity* to the list. */
void EntityList::addEntity(Entity* pNew) {
    if (pNew == NULL) {
        cout << "Pointer to Entity is NULL on addEntity." << endl;
        exit(7);
    }
    list.append(pNew);
}

/* Remove a specific Entity given by a pointer to Entity. */
void EntityList::removeEntity(Entity* pDel) {
    if (pDel == NULL) {
        cout << "Pointer to Entity is NULL on removeEntity." << endl;
        exit(7);
    }

    list.remove(pDel);
}

/* Delete the whole list and desalocate the Entities. */
void EntityList::deleteAll() {
    list.clear();
}

/* Returns a pointer of Entity from the list. */
Entity* EntityList::operator[](int x) {
    if (x >= list.length() || x < 0) {
        std::cout << "ERROR: Segmentation fault on Entity. Exceeded boundaries." << std::endl;
        exit(1);
    }
    Entity* aux = list[x];
    return aux;
}
