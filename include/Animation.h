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
    Animation(GraphicManager* pGraphicM = NULL);
    ~Animation();

    void initializeTexture(const char* path,sf::Vector2u imageCount);
    void setimageCount(const sf::Vector2u imageCount);
    void render();
    void Update(int row, float dt, bool facingLeft, sf::Vector2f position);
    void setGraphicManager(GraphicManager* pGraM) { pGraphicM = pGraM; }
};