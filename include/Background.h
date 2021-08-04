#pragma once

#include "Ente.h"
#include "GraphicManager.h"
#include "stdafx.h"

class Background : public Ente {
public:
    Background(GraphicManager* GM, sf::Vector2f pos, const char* path);
    Background();
    virtual ~Background();

    void initializeSprite();
    void render();
    void update(float dt) { }
};
