#pragma once

#include "Level.h"

class Field : public Level {

public:
    Field();
    ~Field();
    void createPlatform(sf::Vector2f pos);
    void createPlayer(sf::Vector2f pos);
    void createEnemy(sf::Vector2f pos);
    void createLevel();
};
