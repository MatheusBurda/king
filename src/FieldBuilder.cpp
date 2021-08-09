#include "FieldBuilder.h"

FieldBuilder::FieldBuilder(const char* path, Player* p1, Player* p2, sf::Vector2u levelSize) :
Level(path, p1, p2, levelSize) {
    numlvl = 1;
    buildMap();
}

FieldBuilder::~FieldBuilder() {
    saveLvl();
    _list->removeEntity(player1);
    _list->deleteAll();
}

