#pragma once
#include "Level.h"

class CastleBuilder : public Level {
public:
    CastleBuilder(const char* path, Player* p1, Player* p2, sf::Vector2u levelSize);
    ~CastleBuilder();
    void buildMap();
};
