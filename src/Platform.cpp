#include "Platform.h"
#include "Animation.h"
#include "GraphicManager.h"
#include <string.h>

Platform::Platform(sf::Vector2f pos, int platType) :
   Obstacle(pos, sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT),0, ID::platform),
platType(platType) {
    initializeSprite();
}

Platform::~Platform() { }

void Platform::update(float dt) {
    sprite->Update(0, dt, false, position);
}

void Platform::initializeSprite() {
    if (platType == 1)
        sprite->initializeTexture(PLATFORM_PATH_DIRT, sf::Vector2u(1, 1));
    else if (platType == 2)
        sprite->initializeTexture(PLATFORM_PATH_BRICK, sf::Vector2u(1, 1));
    else
        sprite->initializeTexture(PLATFORM_PATH_COBBLE, sf::Vector2u(1, 1));
}

void Platform::save() {
    if (getShowing()) {
        ofstream file;
        file.open("./assets/Saves/Platform.txt", ios::app);
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << getPosition().x << ' ' << getPosition().y << " " << platType << endl;
        file.close();
    }
}