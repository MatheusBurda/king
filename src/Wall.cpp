#include "Wall.h"
#include "Animation.h"
#include "GraphicManager.h"

#include "string.h"

Wall::Wall(sf::Vector2f pos, int wallType, bool facingLeft) :
Obstacle(pos, sf::Vector2f(WALL_WIDTH, WALL_HEIGHT),0, ID::wall),
wallType(wallType) {
    setFacingLeft(facingLeft);
    initializeSprite();
}

Wall::~Wall() {
}

void Wall::update(float dt) {
    sprite->Update(0, dt, facingLeft(), position);
}

void Wall::save() {
    if (getShowing()) {
        ofstream file;
        file.open("./assets/Saves/Wall.txt", ios::app);
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << getPosition().x << ' ' << getPosition().y << ' ' << facingLeft() << ' ' << wallType << endl;
        file.close();
    }
}

void Wall::initializeSprite() {
    if (wallType == 1)
        sprite->initializeTexture(WALL_PATH_DIRT, sf::Vector2u(1, 1));
    else if (wallType == 2)
        sprite->initializeTexture(WALL_PATH_BRICK, sf::Vector2u(1, 1));
    else
        sprite->initializeTexture(WALL_PATH_COBBLE, sf::Vector2u(1, 1));
}
