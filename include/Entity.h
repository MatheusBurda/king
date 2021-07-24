#pragma once

#include "Id.h"
#include "stdafx.h"

class GraphicManager;

using namespace sf;

class Entity {
protected:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f hitbox;
    RectangleShape body;
    RenderWindow* window;
    ID::ids id;
    bool stopx;
    bool stopy;

public:
    Entity(ID::ids id);
    Entity();
    ~Entity();
    void changePosition(sf::Vector2f pos);
    Vector2f getPosition();
    void setVelocity(Vector2f vel);
    Vector2f getVelocity();
    void setHitbox(Vector2f vel);
    Vector2f getHitbox();
    virtual void update(float dt);
    virtual void render();
    void setWindow(RenderWindow* wind) {
        window = wind;
    }
    ID::ids getId();
    virtual void colliding(Entity *ent){}
};