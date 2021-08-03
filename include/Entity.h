#pragma once

#include "Id.h"
#include "stdafx.h"
#include "Ente.h"

class Animation;
class GraphicManager;

using namespace sf;

class Entity : public Ente{
private:
    bool showing;
    bool faceLeft;

protected:
    sf::Vector2f velocity;
    sf::Vector2f hitbox;

public:
    Entity(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit);
    Entity();
    virtual ~Entity();

    void changePosition(const sf::Vector2f pos);
    Vector2f getPosition() const;

    void setVelocity(const Vector2f vel);
    Vector2f getVelocity() const;

    void setHitbox(const Vector2f hit);
    Vector2f getHitbox() const;

    virtual void update(float dt) = 0;
    virtual void initializeSprite() = 0;

    ID::ids getId() const;
    void Move(sf::Vector2f vec);

    void setShowing(const bool val = true) { showing = val; }
    bool getShowing() { return showing; }

    void setFacingLeft(bool facingLeft) { faceLeft = facingLeft; }
    bool facingLeft() const { return faceLeft; }
};