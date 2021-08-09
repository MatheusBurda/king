#pragma once

#include "Level.h"


class FieldBuilder : public Level {
public:
    FieldBuilder(const char* path, Player* p1, Player* p2, sf::Vector2u levelSize);
    ~FieldBuilder();
    void buildMap();
};
