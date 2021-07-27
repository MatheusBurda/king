#include "CollisionManager.h"
#include "Player.h"
CollisionManager::CollisionManager(EntityList* pList) {
    list = pList;
}
CollisionManager::~CollisionManager() {
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
                if (ent1->getId() == ID::player) {
                    switch (ent2->getId()) {

                    case ID::empty:
                        break;

                    case ID::player2:
                        break;

                    case ID::plataform:
                        if (intersectX > intersectY) {
                            if (dx > 0) {
                                ent1->Move(sf::Vector2f(intersectX, 0.0f));
                            } else {
                                ent1->Move(sf::Vector2f(-intersectX, 0.0f));
                            }
                            ent1->setVelocity(sf::Vector2f(0.0f, ent1->getVelocity().y));

                        } else {
                            if (dy > 0) {
                                ent1->Move(sf::Vector2f(0.0f, intersectY));
                                (static_cast<Player*>(ent1))->setJump(true);
                            } else {
                                ent1->Move(sf::Vector2f(0.0f, -intersectY));
                            }
                            ent1->setVelocity(sf::Vector2f(ent1->getVelocity().x, 0.0f));
                        }
                        break;
                        if (intersectX > intersectY) {
                            if (dx > 0) {
                                ent1->Move(sf::Vector2f(intersectX, 0.0f));
                            } else {
                                ent1->Move(sf::Vector2f(-intersectX, 0.0f));
                            }
                            ent1->setVelocity(sf::Vector2f(0.0f, ent1->getVelocity().y));

                        } else {
                            if (dy > 0) {
                                ent1->Move(sf::Vector2f(0.0f, intersectY));
                                (static_cast<Player*>(ent1))->setJump(true);
                            } else {
                                ent1->Move(sf::Vector2f(0.0f, -intersectY));
                            }
                            ent1->setVelocity(sf::Vector2f(ent1->getVelocity().x, 0.0f));
                        }
                    case ID::enemy:
                        if (intersectX > intersectY) {
                            if (dx > 0) {
                                ent1->Move(sf::Vector2f(intersectX, 0.0f));
                                if ((static_cast<Player*>(ent1))->getIsAttacking() && !(static_cast<Player*>(ent1))->facingLeft()) {
                                    (static_cast<Player*>(ent1))->attack((static_cast<Character*>(ent2)));
                                    (static_cast<Player*>(ent1))->setIsAttacking(false);
                                }
                            } else {
                                ent1->Move(sf::Vector2f(-intersectX, 0.0f));
                                if ((static_cast<Player*>(ent1))->getIsAttacking() && (static_cast<Player*>(ent1))->facingLeft()) {
                                    (static_cast<Player*>(ent1))->attack((static_cast<Character*>(ent2)));
                                    (static_cast<Player*>(ent1))->setIsAttacking(false);
                                }
                            }

                        } else {
                            if (dy > 0) {
                                ent1->Move(sf::Vector2f(0.0f, intersectY));
                                (static_cast<Player*>(ent1))->setJump(true);
                            } else {
                                ent1->Move(sf::Vector2f(0.0f, -intersectY));
                            }
                            ent1->setVelocity(sf::Vector2f(ent1->getVelocity().x, 0.0f));
                        }

                        break;

                    default:
                        break;
                    }
                } else if (ent1->getId() == ID::enemy) {
                    switch (ent2->getId()) {

                    case ID::empty:
                        break;
                    case ID::player:
                        if (intersectX > intersectY) {
                            if (dx > 0) {
                                ent1->Move(sf::Vector2f(intersectX, 0.0f));
                            } else {
                                ent1->Move(sf::Vector2f(-intersectX, 0.0f));
                                ent1->setVelocity(sf::Vector2f(0.0f, ent1->getVelocity().y));
                            }

                        } else {
                            if (dy > 0) {
                                ent1->Move(sf::Vector2f(0.0f, intersectY));

                            } else {
                                ent1->Move(sf::Vector2f(0.0f, -intersectY));
                            }
                            ent1->setVelocity(sf::Vector2f(ent1->getVelocity().x, 0.0f));
                        }

                        break;
                    case ID::player2:
                        break;

                    case ID::plataform:
                        if (intersectX > intersectY) {
                            if (dx > 0) {
                                ent1->Move(sf::Vector2f(intersectX, 0.0f));
                            } else {
                                ent1->Move(sf::Vector2f(-intersectX, 0.0f));
                            }
                            ent1->setVelocity(sf::Vector2f(0.0f, ent1->getVelocity().y));

                        } else {
                            if (dy > 0) {
                                ent1->Move(sf::Vector2f(0.0f, intersectY));
                            } else {
                                ent1->Move(sf::Vector2f(0.0f, -intersectY));
                            }
                            ent1->setVelocity(sf::Vector2f(ent1->getVelocity().x, 0.0f));
                        }
                        break;
                        if (intersectX > intersectY) {
                            if (dx > 0) {
                                ent1->Move(sf::Vector2f(intersectX, 0.0f));
                            } else {
                                ent1->Move(sf::Vector2f(-intersectX, 0.0f));
                            }
                            ent1->setVelocity(sf::Vector2f(0.0f, ent1->getVelocity().y));

                        } else {
                            if (dy > 0) {
                                ent1->Move(sf::Vector2f(0.0f, intersectY));
                            } else {
                                ent1->Move(sf::Vector2f(0.0f, -intersectY));
                            }
                            ent1->setVelocity(sf::Vector2f(ent1->getVelocity().x, 0.0f));
                        }
                    case ID::enemy:
                        break;

                    default:
                        break;
                    }
                }
            } else {
            }
        }
    }
}