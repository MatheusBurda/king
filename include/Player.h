#pragma once

#include "Character.h"

class Animation;
class GraphicManager;

#define PLAYER_PATH "./assets/King/KingSpritesheet.png"

class Player : public Character {
private:
    bool Canjump;
    bool firstAttack;
    float totalTime;
    static const float attackTime;

public:
    Player(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg);
    ~Player();
    void update(float dt);
    void render();
    void setJump(const bool val = true) { Canjump = val; }
    void initializeSprite();
    int canAttack();
};

