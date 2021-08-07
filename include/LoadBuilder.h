#pragma once
#include "Level.h"
class LoadBuilder :public Level
{
public:
    LoadBuilder(const char* path, EntityList* EL, Player* p1, Player* p2, CollisionManager* CM, sf::Vector2u levelSize);
    ~LoadBuilder();
    void buildMap();
};

