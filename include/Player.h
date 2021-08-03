#pragma once

#include "Character.h"

class Animation;
class GraphicManager;

#define PLAYER_PATH "./assets/King/KingSpritesheet2.png"

class Player : public Character {
private:
    bool canJump;
    bool firstAttack;
    float totalTimeFromAttack;
    static const float attackTime;
    bool isWalking;

public:
    Player(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg);
    ~Player();
    void update(float dt);
    void render();
    void setJump(const bool val = true) { canJump = val; }
    void initializeSprite();
    int canAttack(float dt = 0.0f);
    void walk(bool left);
    void jump();
    void setIsWalking(const bool val) { isWalking = val; }
};
