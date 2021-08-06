#pragma once

#include "Character.h"
#include "PlayerControl.h"

class Animation;

#define PLAYER_PATH "./assets/King/KingSpritesheet2.png"

class Player : public Character {
private:
    bool canJump;
    bool firstAttack;
    float totalTimeFromAttack;
    static const float attackTime;
    bool isWalking;
    const bool player1;
    const sf::String nickname;
    PlayerControl pc;

public:
    Player(const bool isPlayer1 = true, const sf::String nickname = "");
    ~Player();

    void update(float dt);
    void render();
    void setJump(const bool val = true) { canJump = val; }
    void initializeSprite();
    int canAttack(float dt = 0.0f);
    void walk(bool left);
    void jump();
    void setIsWalking(const bool val) { isWalking = val; }
    void updateSprite(float dt);
    const bool isPlayer1() const { return player1; }
    void reset();
};
