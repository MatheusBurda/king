#pragma once
#include "Enemy.h"
#include "Arrow.h"
#define ARCHER_PATH "./assets/Archer/ArcherSpritesheet.png"
class Animation;
class GraphicManager;
class Archer :public Enemy
{
private:
    Arrow* arrow;
public:
    Archer(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg, Arrow* arr);
    ~Archer();
    void initializeSprite();
    void update(float dt);
    void attack();
};