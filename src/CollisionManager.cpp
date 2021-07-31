#include "CollisionManager.h"
#include "Player.h"

CollisionManager::CollisionManager(EntityList* pList) {
    list = pList;
}

CollisionManager::~CollisionManager() {
    list = NULL;
}

void CollisionManager::toCollide() {
    Entity *ent1, *ent2;

    for (int i = 0; i < list->getSize(); i++) {
        for (int j = i + 1; j < list->getSize(); j++) {

            ent1 = (*list)[i];
            ent2 = (*list)[j];

            float dy, dx, intersectX, intersectY;
            dx = ent2->getPosition().x - ent1->getPosition().x;
            dy = ent2->getPosition().y - ent1->getPosition().y;

            intersectX = abs(dx) - (ent1->getHitbox().x / 2 + ent2->getHitbox().x / 2);
            intersectY = abs(dy) - (ent1->getHitbox().y / 2 + ent2->getHitbox().y / 2);

            if (intersectX < 0.0f && intersectY < 0.0f) { //Condition to collide...
                if (ent1->getId() == ID::player || ent1->getId() == ID::player2) {
                    collidePlayer(ent1, ent2, dx, dy, intersectX, intersectY);
                } else if (ent1->getId() == ID::enemy) {
                    collideEnemy(ent1, ent2, dx, dy, intersectX, intersectY);
                } else if (ent1->getId() == ID::fireball && ent1->getShowing()) {
                    collideFireball(ent1, ent2, dx, dy, intersectX, intersectY);
                }
                else if (ent1->getId() == ID::platform) {
                    collidePlatform(ent1, ent2, dx, dy, intersectX, intersectY);
                }
            }
        }
    }
}

//function to move the entities using their velocity as reference (X axis)
void CollisionManager::moveX(Entity* ent1, Entity* ent2, float intersectX) {
    ent1->Move(sf::Vector2f(intersectX * ent1->getVelocity().x / ((abs(ent1->getVelocity().x) + abs(ent2->getVelocity().x) + DIV0)), 0.0f));
    ent2->Move(sf::Vector2f(intersectX * ent2->getVelocity().x / ((abs(ent1->getVelocity().x) + abs(ent2->getVelocity().x) + DIV0)), 0.0f));
}

//function to move the entities using their velocity as reference (Y axis)
void CollisionManager::moveY(Entity* ent1, Entity* ent2, float intersectY) {

    ent1->Move(sf::Vector2f(0.0f, intersectY * ent1->getVelocity().y / ((abs(ent1->getVelocity().y) + abs(ent2->getVelocity().y) + DIV0))));
    ent2->Move(sf::Vector2f(0.0f, intersectY * ent2->getVelocity().y / ((abs(ent1->getVelocity().y) + abs(ent2->getVelocity().y) + DIV0))));

    ent1->setVelocity(sf::Vector2f(ent1->getVelocity().x, 0.0f));
    ent2->setVelocity(sf::Vector2f(ent2->getVelocity().x, 0.0f));
}

//player isnt allouwed to stop above enemy and vice versa
void CollisionManager::notAbove(Entity* ent1, Entity* ent2, float intersectX, float dx) {
    if (ent1->getPosition().y > ent2->getPosition().y)
        if (dx > 0)
            ent2->Move(sf::Vector2f(-intersectX, 0.0f));
        else
            ent2->Move(sf::Vector2f(intersectX, 0.0f));
    else if (dx > 0)
        ent1->Move(sf::Vector2f(-intersectX, 0.0f));
    else
        ent1->Move(sf::Vector2f(intersectX, 0.0f));
}

//function to collide player with any other entity
void CollisionManager::collidePlayer(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY) {
    switch (ent2->getId()) {

    case ID::empty:
        break;

    case ID::player2:
        break;

    case ID::platform:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
        } else {
            if (dy > 0.0f) {
                moveY(ent1, ent2, intersectY);
                (static_cast<Player*>(ent1))->setJump(true);
            } else {
                moveY(ent1, ent2, intersectY);
            }
        }
        break;

    case ID::enemy:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);

        } else {
            notAbove(ent1, ent2, intersectX, dx);
        }
        break;
    case ID::fireball:
        if (ent2->getShowing())
            attackEnemy(ent1, ent2);
    default:
        break;
    }
}

//function to collide enemy with any other entity
void CollisionManager::collideEnemy(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY) {
    switch (ent2->getId()) {

    case ID::empty:
        break;

    case ID::player:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
        } else {
            notAbove(ent1, ent2, intersectX, dx);
        }
        break;

    case ID::player2:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
        } else {
            notAbove(ent1, ent2, intersectX, dx);
        }
        break;

    case ID::platform:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
        } else {
            moveY(ent1, ent2, intersectY);
        }
        break;

    case ID::enemy:
        break;
    case ID::fireball:
        break;

    default:
        break;
    }
}

//function to collide fireball with any other entity
void CollisionManager::collideFireball(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY) {
    switch (ent2->getId()) {

    case ID::empty:
        break;

    case ID::player:
        attackEnemy(ent1, ent2);
        break;

    case ID::player2:
        attackEnemy(ent1, ent2);
        break;

    case ID::platform:
        ent1->setShowing(false);
        break;

    case ID::enemy:
        break;

    default:
        break;
    }
}
//function to collide a projectile with a player
void CollisionManager::attackEnemy(Entity* ent1, Entity* ent2) {
    if (ent1->getId() == ID::fireball) {
        ent1->setShowing(false);
        ent1->setVelocity(sf::Vector2f(0.0f, 0.0f));
        (static_cast<Player*>(ent2))->getHurt(FIREBALL_DAMAGE);
    } else {
        ent2->setShowing(false);
        ent2->setVelocity(sf::Vector2f(0.0f, 0.0f));
        (static_cast<Player*>(ent1))->getHurt(FIREBALL_DAMAGE);
    }
}
void CollisionManager::attackPlayer(Entity* ent1, Entity* ent2) {
    if (ent1->getId() == ID::player && (static_cast<Character*>(ent1))->getIsAttacking()) {
        (static_cast <Character*>(ent2))->getHurt(PLAYER_DAMAGE);
    }
    else if((static_cast<Character*>(ent2))->getIsAttacking()) {
        (static_cast <Character*>(ent1))->getHurt(PLAYER_DAMAGE);    
    }
}
void CollisionManager::collidePlatform(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY) {
    switch (ent2->getId()) {

    case ID::empty:
        break;
    case ID::player:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
        }
        else {
            if (dy < 0.0f) {
                moveY(ent1, ent2, intersectY);
                (static_cast<Player*>(ent2))->setJump(true);
            }
            else {
                moveY(ent1, ent2, intersectY);
            }
        }
    case ID::player2:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
        }
        else {
            if (dy < 0.0f) {
                moveY(ent1, ent2, intersectY);
                (static_cast<Player*>(ent2))->setJump(true);
            }
            else {
                moveY(ent1, ent2, intersectY);
            }
        }

    case ID::platform:
        break;

    case ID::enemy:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
        }
        else {
            if (dy > 0.0f) {
                moveY(ent1, ent2, intersectY);
            }
            else {
                moveY(ent1, ent2, intersectY);
            }
        }
        break;
    case ID::fireball:
        ent2->setShowing(false);
    default:
        break;
    }
}
