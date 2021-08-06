#pragma once
#include "Level.h"


class CastleBuilder : public Level {
public:
    CastleBuilder(const char* path, EntityList* EL, Player* p1, Player* p2, CollisionManager* CM, sf::Vector2u levelSize);
    ~CastleBuilder();
    void buildMap();

};
