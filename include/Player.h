#pragma once

#include "Character.h"
#include "PlayerControl.h"

class Animation;
class InputManager;

#define PLAYER_1_PATH "./assets/King/KingSpritesheet.png"
#define PLAYER_2_PATH "./assets/King/KingSpritesheet2.png"

class Player : public Character {
private:
    bool canJump;
    bool firstAttack;
    float totalTimeFromAttack;
    static const float attackTime;
    bool isWalking;
    const bool player1;
    PlayerControl pc;
    int points;

public:
    Player(const bool isPlayer1 = true, InputManager* pIM = NULL);
    ~Player();

    void update(float dt);
    void setJump(const bool val = true) { canJump = val; }
    void initializeSprite();
    int canAttack(float dt = 0.0f);
    void walk(bool left);
    void jump();
    void setIsWalking(const bool val) { isWalking = val; }
    void updateSprite(float dt);
    const bool isPlayer1() const { return player1; }
    void reset();
    void save();
    void updatePoints(int pt);
    int getPoints() { return points; }
};
