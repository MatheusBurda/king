#pragma once

#include "Id.h"
#include "stdafx.h"

class Animation;

class Ent {
protected:
    Animation* sprite;
    ID::ids id;
    sf::Vector2f position;

public:
    Ent(ID::ids id,sf::Vector2f pos);
    Ent();
    virtual ~Ent();

    void changePos(const sf::Vector2f pos);
    sf::Vector2f getPos() const;
    void MoveBody(const sf::Vector2f vec);
    ID::ids getID() const;

    virtual void initializeSprite() = 0;
    virtual void update(float dt) = 0;
    virtual void render();
};
