#pragma once

#include "Level.h"


class FieldBuilder : public Level {
public:
    FieldBuilder(const char* path, EntityList* EL, Player* p1, Player* p2, CollisionManager* CM, sf::Vector2u levelSize);
    ~FieldBuilder();
    void buildMap();
    Level* getField() { return this; }
};
