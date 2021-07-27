#pragma once

#include "Character.h"

class Animation;
class GraphicManager;

#define PATH_ENEMY_TEXTURE "./assets/EvilWizard/Idle.png"

class Enemy : public Character {

public:
    Enemy(GraphicManager* GM);
    ~Enemy();
    void update(float dt);
    void render();
    void initializeSprite();
};
