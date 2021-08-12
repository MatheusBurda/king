#pragma once
#include "Enemy.h"

class Animation;

#define BOSS_PATH "./assets/Boss/BossSpritesheet.png"
#define BOSS_VELOCITYX 300
#define BOSS_MOTIONX_MAX 500
#define BOSS_MOTIONX_MIN 200
#define BOSS_HEIGHT 110
#define BOSS_WIDTH 40
#define BOSS_LIFE 4000
#define BOSS_DMG 30
#define BOSS_ATTACK 200

class Boss : public Enemy {
private:
    static const float attackTime;

public:
    Boss(sf::Vector2f pos, Player* pPlayer1 = NULL, Player* pPlayer2 = NULL);
    ~Boss();
    void initializeSprite();
    void update(float dt);
    void save();
    void attack() { }
};
