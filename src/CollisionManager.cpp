#include "CollisionManager.h"
#include "Player.h"

CollisionManager::CollisionManager(EntityList* pList) {
    list = pList;
}

CollisionManager::~CollisionManager() {
}

void CollisionManager::toCollide() {
    Entity* ent1, * ent2;

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
                }
                else if (ent1->getId() == ID::enemy) {
                    collideEnemy(ent1, ent2, dx, dy, intersectX, intersectY);
                }

            }
            else {
                //there is no collision between ent1 && ent2
            }
        }
    }
}
//function to move the entities using their velocity as reference (X axis)
void CollisionManager::moveX(Entity * ent1, Entity * ent2, float intersectX) {
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
    if(ent1->getPosition().y>ent2->getPosition().y)
        if(dx>0)
            ent2->Move(sf::Vector2f(-intersectX, 0.0f));
        else
            ent2->Move(sf::Vector2f(intersectX, 0.0f));
    else
        if(dx>0)
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

    case ID::plataform:
        if (intersectX > intersectY) {
                moveX(ent1, ent2, intersectX);
        }else {
            if (dy > 0.0f) {
                moveY(ent1, ent2, intersectY);
                (static_cast<Player*>(ent1))->setJump(true);
            }
            else {
                moveY(ent1, ent2, intersectY);
            }
        }
        break;

    case ID::enemy:
        if (intersectX > intersectY) {
                moveX(ent1, ent2, intersectX);
        }else {
                notAbove(ent1, ent2, intersectX, dx);
        }
        break;

    default:
        break;
    }
}
//function to collide enemy with any other entity
void CollisionManager:: collideEnemy(Entity* ent1, Entity* ent2, float dx, float dy, float intersectX, float intersectY) {
    switch (ent2->getId()) {

    case ID::empty:
        break;

    case ID::player:
        if (intersectX > intersectY) {
                moveX(ent1, ent2, intersectX);
        }else {
                notAbove(ent1, ent2, intersectX, dx);
        }
        break;

    case ID::player2:
        if (intersectX > intersectY) {
                moveX(ent1, ent2, intersectX);
        }else{
               notAbove(ent1, ent2, intersectX, dx);
        }
        break;

    case ID::plataform:
        if (intersectX > intersectY) {
             moveX(ent1, ent2, intersectX);
        }else {
                moveY(ent1, ent2, intersectY);
        }
        break;

    case ID::enemy:
        break;

    default:
        break;
    }
}