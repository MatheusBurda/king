#pragma once
#include "Level.h"

class LevelBuilder {
public:
    LevelBuilder() { }
    virtual ~LevelBuilder() { }
    void buildPlatform(sf::Vector2f pos, Level* lvl, const char path[100]);
    void buildPlayer1(sf::Vector2f pos, Level* lvl);
    void buildWizard(sf::Vector2f pos, Level* lvl);
    void buildArcher(sf::Vector2f pos, Level* lvl);
    void buildWall(sf::Vector2f pos, Level* lvl, const char* path, bool faceLeft);
    virtual void buildMap() = 0;
};
