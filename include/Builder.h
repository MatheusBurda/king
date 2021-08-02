#pragma once
#include "Level.h"

class Builder{
public:
    Builder(){ }
    ~Builder(){ }
    virtual void buildPlatform(sf::Vector2f pos) = 0;
    virtual void buildPlayer1(sf::Vector2f pos) = 0;
    virtual void buildWizard(sf::Vector2f pos) = 0;
    virtual void buildArcher(sf::Vector2f pos)=0;
    virtual void buildWall(sf::Vector2f pos) = 0;
    virtual void buildMap() = 0;
};

