#pragma once
#include "Enemy.h"

#define WIZARD_PATH "./assets/EvilWizard/EvilWizard.png"
#define WIZARD_WIDTH 44
#define WIZARD_HEIGHT 105
#define WIZARD_LIFE 2000
#define WIZARD_DAMAGE 25
#define WIZARD_VELOCITY 300
#define MAX_VAR_HEIGHT 100

class Animation;
class Player;

class Wizard : public Enemy {
private:
    Fireball* fireball;
    static const float attackTime;
    const float maxHeight;
    const float minHeight;

public:
    Wizard(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), Fireball* fireb = NULL, Player* pPlayer1 = NULL, Player* pPlayer2 = NULL);
    ~Wizard();
    void initializeSprite();
    void update(float dt);
    void attack();
    void save();
    void followPlayer();
};
