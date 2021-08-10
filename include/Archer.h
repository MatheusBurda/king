#pragma once
#include "Arrow.h"
#include "Enemy.h"
#define ARCHER_PATH "./assets/Archer/ArcherSpritesheet.png"

class Animation;
class GraphicManager;

class Archer : public Enemy {
private:
    Arrow* arrow;
    static const float attackTime;

public:
    Archer(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg, Arrow* arr);
    ~Archer();
    void initializeSprite();
    void update(float dt);
    void attack();
    void save();
};