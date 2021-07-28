#pragma once

#include "Id.h"
#include "stdafx.h"

class GraphicManager;
class Animation;

using namespace sf;

class Entity {
protected:
    Animation* sprite;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f hitbox;
    ID::ids id;
    bool showing;
    bool faceLeft;

public:
    Entity(ID::ids id, GraphicManager* GM);
    Entity();
    virtual ~Entity();

    void changePosition(const sf::Vector2f pos);
    Vector2f getPosition() const;

    void setVelocity(const Vector2f vel);
    Vector2f getVelocity() const;

    void setHitbox(const Vector2f vel);
    Vector2f getHitbox() const;

    virtual void update(float dt) = 0;
    virtual void render() = 0;

    ID::ids getId() const;
    void Move(sf::Vector2f vec);

    void setShowing(const bool val = true) { showing = val; }
    bool getShowing() { return showing; }

    virtual void initializeSprite() = 0;

    void setFacingLeft(bool facingLeft) { faceLeft = facingLeft; }
    bool facingLeft() const { return faceLeft; }
};