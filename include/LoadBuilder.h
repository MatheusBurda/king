#pragma once
#include "Level.h"
class LoadBuilder :public Level
{
public:
    LoadBuilder(const char* path, Player* p1, Player* p2, sf::Vector2u levelSize);
    ~LoadBuilder();
    void buildMap();
};

