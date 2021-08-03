#pragma once
#include "Level.h"

class Builder{
public:
    Builder(){ }
    virtual ~Builder(){ }
    void buildPlatform(sf::Vector2f pos, Level *lvl, char path[100]);
    void buildPlayer1(sf::Vector2f pos, Level* lvl);
    void buildWizard(sf::Vector2f pos, Level* lvl);
    void buildArcher(sf::Vector2f pos, Level* lvl);
    void buildWall(sf::Vector2f pos, Level* lvl);
    virtual void buildMap() = 0;
};

