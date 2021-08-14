#pragma once

#include "Arrow.h"
#include "Enemy.h"

#define ARCHER_PATH "./assets/Archer/ArcherSpritesheet.png"

#define ARCHER_WIDTH 50
#define ARCHER_HEIGHT 90
#define ARCHER_LIFE 2000
#define ARCHER_DAMAGE 25
#define ARCHER_VELOCITYX 300
#define ARCHER_MOTIONX_MAX 500
#define ARCHER_MOTIONX_MIN 200
#define ARCHER_ATTACKX 1000


class Animation;
class GraphicManager;

class Archer : public Enemy {
private:
    Arrow* arrow;
    static const float attackTime;

public:
    Archer(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), Arrow* fireb = NULL, Player* pPlayer1 = NULL, Player* pPlayer2 = NULL);
    ~Archer();
    void initializeSprite();
    void update(float dt);
    void attack();
    void save();
    void updateSprite(float dt);
};