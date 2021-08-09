#include "CastleBuilder.h"


CastleBuilder::CastleBuilder(const char* path, Player* p1, Player* p2, sf::Vector2u levelSize) :
    Level(path, p1, p2, levelSize) {
    numlvl = 2;
    buildMap();
}

CastleBuilder::~CastleBuilder() {
    saveLvl();
    _list->removeEntity(player1);
    _list->deleteAll();
}
