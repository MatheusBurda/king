#pragma once
#include "Enemy.h"
#define WIZARD_PATH "./assets/EvilWizard/EvilWizard.png"
class Animation;
class GraphicManager;
class Wizard :public Enemy
{
private:
    Fireball* fireball;
    static const float attackTime;
public:
    Wizard(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg, Fireball* fireb);
    ~Wizard();
    void initializeSprite();
    void update(float dt);
    void attack();
    void save();
};

