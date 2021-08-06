#pragma once
#include "LevelBuilder.h"
class BossBuilder :
    public LevelBuilder
{
    Level* boss;
public:
    BossBuilder();
    ~BossBuilder();
    void buildMap();
    Level* getBoss() { return boss; }
};

