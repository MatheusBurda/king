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
            bool attack = ((ent1->getId() == ID::player && (ent2->getId() == ID::wizard || ent2->getId() == ID::archer || ent2->getId() == ID::boss)) || 
                           (ent2->getId() == ID::player && (ent1->getId() == ID::wizard || ent1->getId() == ID::archer || ent1->getId() == ID::boss)));
            float dy, dx, intersectX, intersectY;
            dx = ent2->getPosition().x - ent1->getPosition().x;
            dy = ent2->getPosition().y - ent1->getPosition().y;

            intersectX = abs(dx) - (ent1->getHitbox().x / 2 + ent2->getHitbox().x / 2);
            intersectY = abs(dy) - (ent1->getHitbox().y / 2 + ent2->getHitbox().y / 2);
            if (attack) {
                attackPlayer(ent1, ent2, dx, dy);
                enemyMotion(ent1, ent2, dx, dy);
            }
            if (intersectX < 0.0f && intersectY < 0.0f && ent1->getShowing() && ent2->getShowing()) { //Condition to collide...
                if (ent1->getId() == ID::player || ent1->getId() == ID::player2) {
                    collidePlayer(ent1, ent2, dx, dy, intersectX, intersectY);
                } else if (ent1->getId() == ID::wizard || ent1->getId()== ID::archer || ent1->getId()==ID::boss) {
                    collideEnemy(ent1, ent2, dx, dy, intersectX, intersectY);
                } else if (ent1->getId() == ID::fireball || ent1->getId()==ID::arrow) {
                    collideProjectile(ent1, ent2, dx, dy, intersectX, intersectY);
                }
                else if (ent1->getId() == ID::platform || ent1->getId() == ID::wall) {
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

    case ID::platform:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
            ent1->setVelocity(sf::Vector2f(0,ent1->getVelocity().y));
        } else {
            if (dy > 0.0f) {
                moveY(ent1, ent2, intersectY);
                (static_cast<Player*>(ent1))->setJump(true);
            } else {
                moveY(ent1, ent2, intersectY);
            }
        }
        break;
    case ID::wall:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
            ent1->setVelocity(sf::Vector2f(0, ent1->getVelocity().y));
        }

        break;

    case ID::wizard:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);

        } else {
            notAbove(ent1, ent2, intersectX, dx);
        }
        break;
    case ID::archer:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);

        }
        else {
            notAbove(ent1, ent2, intersectX, dx);
        }
        break;
    case ID::boss:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);

        }
        else {
            notAbove(ent1, ent2, intersectX, dx);
        }
        break;
    case ID::fireball:
            attackEnemy(ent2, ent1);
    case ID::arrow:
            attackEnemy(ent2, ent1);
    case ID::spiderweb:
        ent1->setVelocity(sf::Vector2f(ent1->getVelocity().x / 2, ent1->getVelocity().y / 2));
    case ID::lava:
        (static_cast<Character*>(ent1))->getHurt(LAVA_DAMAGE);

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
    case ID::wall:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
        }
        break;
    default:
        break;
    }
}

//function to collide projectile with any other entity
void CollisionManager::collideProjectile(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY) {
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
    case ID::wall:
        ent1->setShowing(false);

    default:
        break;
    }
}
//function to collide a projectile with a player
void CollisionManager::attackEnemy(Entity* ent1, Entity* ent2) {
    if (ent1->getId() == ID::player || ent1->getId()==ID::player2) {
        ent2->setShowing(false);
        ent2->setVelocity(sf::Vector2f(0.0f, 0.0f));
        (static_cast<Player*>(ent1))->getHurt(PROJECTILE_DAMAGE);
    } else {
        ent1->setShowing(false);
        ent1->setVelocity(sf::Vector2f(0.0f, 0.0f));
        (static_cast<Player*>(ent2))->getHurt(PROJECTILE_DAMAGE);
    }
}
void CollisionManager::enemyMotion(Entity* ent1, Entity* ent2, float dx, float dy) {
    if (abs(dx) < ENEMY_MOTIONX_MAX && abs(dx)>ENEMY_MOTIONX_MIN) {
        if (dx > 0) {
            if (ent1->getId() == ID::player) {
                (static_cast <Character*>(ent2))->setVelocity(sf::Vector2f(-ENEMY_VELOCITYX, ent2->getVelocity().y));
                ent2->setFacingLeft(true);
            }
            else if (ent2->getId() == ID::player) {
                (static_cast <Character*>(ent1))->setVelocity(sf::Vector2f(-ENEMY_VELOCITYX, ent1->getVelocity().y));
                ent1->setFacingLeft(true);
            }
        }
        else {
            if (ent1->getId() == ID::player) {
                (static_cast <Character*>(ent2))->setVelocity(sf::Vector2f(ENEMY_VELOCITYX, ent2->getVelocity().y));
                ent2->setFacingLeft(false);
            }
            else if (ent2->getId() == ID::player) {
                (static_cast <Character*>(ent1))->setVelocity(sf::Vector2f(ENEMY_VELOCITYX, ent1->getVelocity().y));
                ent1->setFacingLeft(true);
            }
        }
    }
    else {
        if (ent1->getId() == ID::player)
            ent2->setVelocity(sf::Vector2f(0, ent2->getVelocity().y));
        else
            ent1->setVelocity(sf::Vector2f(0, ent1->getVelocity().y));
    }
}
void CollisionManager::attackPlayer(Entity* ent1, Entity* ent2,float dx, float dy) {
    if (abs(dy)<100 && abs(dx) < PLAYER_ATTACK) {
        if (dx > 0) {
            if (ent1->getId() == ID::player && (static_cast<Character*>(ent1))->getIsAttacking() && !ent1->facingLeft()) {
                (static_cast <Character*>(ent2))->getHurt(PLAYER_DAMAGE);
            }
            else if (ent2->getId() == ID::player && (static_cast<Character*>(ent2))->getIsAttacking()&& ent2->facingLeft()) {
                (static_cast <Character*>(ent1))->getHurt(PLAYER_DAMAGE);
            }
        }
        else {
            if (ent1->getId() == ID::player && (static_cast<Character*>(ent1))->getIsAttacking() && ent1->facingLeft()) {
                (static_cast <Character*>(ent2))->getHurt(PLAYER_DAMAGE);
            }
            else if (ent2->getId() == ID::player && (static_cast<Character*>(ent2))->getIsAttacking() && !ent2->facingLeft()) {
                (static_cast <Character*>(ent1))->getHurt(PLAYER_DAMAGE);
            }
        }
    }
}
void CollisionManager::collidePlatform(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY) {
    switch (ent2->getId()) {

    case ID::player:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
            ent2->setVelocity(sf::Vector2f(0, ent2->getVelocity().y));
        }
        else {
            if (ent1->getId() == ID::platform) {
                if (dy < 0.0f) {
                    moveY(ent1, ent2, intersectY);
                    (static_cast<Player*>(ent2))->setJump(true);
                }
                else {
                    moveY(ent1, ent2, intersectY);
                }
            }
        }
    case ID::player2:
        if (intersectX > intersectY) {
            moveX(ent1, ent2, intersectX);
            ent2->setVelocity(sf::Vector2f(0, ent2->getVelocity().y));
        }
        else {
            if (ent1->getId() == ID::platform) {
                if (dy < 0.0f) {
                    moveY(ent1, ent2, intersectY);
                    (static_cast<Player*>(ent2))->setJump(true);
                }
                else {
                    moveY(ent1, ent2, intersectY);
                }
            }
        }

    case ID::wizard:
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
    case ID::archer:
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
    case ID::boss:
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
    case ID::arrow:
        ent2->setShowing(false);
    default:
        break;
    }
}
