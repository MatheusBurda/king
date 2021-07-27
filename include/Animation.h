#pragma once

#include "GraphicManager.h"
#include "stdafx.h"

class Animation {
private:
    GraphicManager* pGraphicM;
    sf::Vector2u imageCount;
    sf::Texture* texture;
    sf::Vector2u currentImage;
    sf::RectangleShape body;
    sf::IntRect uvRect;
    float totalTime;
    static const float switchTime;

public:
    Animation(GraphicManager* pGraphicM = NULL, sf::Vector2u imageCount = sf::Vector2u(1, 1));
    ~Animation();

    void initializeTexture(const char* path = "", ID::ids id = ID::empty);
    void setimageCount(const sf::Vector2u imageCount);
    void render();
    void Update(int row, float dt, bool facingLeft, sf::Vector2f position);
};

const float Animation::switchTime = 0.067;