#pragma once

#include "Ent.h"
#include "GraphicManager.h"
#include "stdafx.h"

class Background : public Ent {
public:
    Background(sf::Vector2f pos, const char* path);
    Background();
    virtual ~Background();

    void initializeSprite();
    void render();
    void update(float dt) { }
};
