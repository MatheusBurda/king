#pragma once
#include "Enemy.h"


class Animation;
class GraphicManager;
#define BOSS_PATH "./assets/Archer/Attack1.png"
class Boss :public Enemy{
private:
	static const float attackTime;
public:
    Boss(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg);
    ~Boss();
    void initializeSprite();
    void update(float dt);
    void save();
    void attack(){ }
    void render();
};

