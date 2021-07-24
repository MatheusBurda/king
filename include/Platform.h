#pragma once

#include "Entity.h"

class Platform : public Entity {
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Platform(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f));
    ~Platform();

    void update();
    void render();
};
