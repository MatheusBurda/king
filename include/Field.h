#pragma once
#include "Level.h"
class Field : public Level
{

public:
    Field();
    ~Field();
    void createPlatform();
    void createPlayer();
    void createEnemy();
};

