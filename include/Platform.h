#pragma once

#include "Entity.h"

#define PLATFORM_PATH "./assets/Platforms/DirtPlatform.png"
class GraphicManager;

class Platform : public Entity {

public:
    Platform(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), GraphicManager* GM = NULL);
    ~Platform();

    void update(float dt);
    void render();
    void inicializar();
};
